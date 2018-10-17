#include "Answer.hpp"
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>

namespace hpc {

struct PieceWithTurn {
  Piece piece;
  int turn;

  PieceWithTurn(const Piece& p, int t) : piece(p), turn(t) {}

  bool collides(const PieceWithTurn& a) {
    return this->piece.pos().x < a.piece.pos().x + a.piece.width() &&
           this->piece.pos().x + this->piece.width() > a.piece.pos().x &&
           this->piece.pos().y < a.piece.pos().y + a.piece.height() &&
           this->piece.pos().y + this->piece.height() > a.piece.pos().y &&
           this->turn <= a.turn + a.piece.requiredHeatTurnCount() &&
           this->turn + this->piece.requiredHeatTurnCount() >= a.turn;
  }

  bool collides(const std::vector<PieceWithTurn>& a) {
    bool r = false;
    for (auto e : a) {
      r |= this->collides(e);
    }
    return r;
  }
};

bool arePiecesHorizontal;
std::vector<PieceWithTurn> reservedPieces;

Answer::Answer() {}

Answer::~Answer() {}

void Answer::init(const Stage& aStage) {
  // auto recipe = aStage.candidateLane(CandidateLaneType_Large).recipe();
  // arePiecesHorizontal = (recipe.foldPosRatioMin() + recipe.foldPosRatioTerm()) / 2.0 > 0.5;
  reservedPieces.clear();
}

Action Answer::decideNextAction(const Stage& aStage) {
  // 生地置き場にあるクッキーの形状を調べる。
  {
    int verticalPieceCount = 0;
    for (auto type : {CandidateLaneType_Small, CandidateLaneType_Large}) {
      for (int i = 0; i < Parameter::CandidatePieceCount; i++) {
        auto& piece = aStage.candidateLane(type).pieces()[i];
        verticalPieceCount += piece.width() < piece.height();
      }
    }
    arePiecesHorizontal = verticalPieceCount < Parameter::CandidatePieceCount;
  }

  // オーブンにあるクッキーを読み取る。
  std::vector<PieceWithTurn> bakingPieces;
  for (auto piece : aStage.oven().bakingPieces()) {
    bakingPieces.push_back(PieceWithTurn(piece, aStage.turn() - piece.currentHeatTurnCount()));
  }

  // 大きいクッキーの置き方を予め決めておく。
  if (!reservedPieces.size()) {
    // より大きいクッキーを先に試すように並び替える。
    std::vector<int> order(Parameter::CandidatePieceCount);
    std::iota(begin(order), end(order), 0);
    sort(order.begin(), order.end(), [&aStage](int a, int b) {
      auto pieceA = aStage.candidateLane(CandidateLaneType_Large).pieces()[a];
      auto pieceB = aStage.candidateLane(CandidateLaneType_Large).pieces()[b];
      int sizeA = pieceA.height() * pieceA.width();
      int sizeB = pieceB.height() * pieceB.width();
      return sizeA != sizeB ? sizeA > sizeB : a < b;
    });

    // 大きいクッキーを左上から詰めて置く。
    int putPieceCount = 0;
    std::vector<bool> isUsed(Parameter::CandidatePieceCount);
    for (int t = aStage.turn();
         putPieceCount < Parameter::CandidatePieceCount && t <= aStage.turn() + Parameter::GameTurnLimit; t++) {
      bool didPut = false;

      for (int i = 0; !didPut && i < Parameter::CandidatePieceCount; i++) {
        if (isUsed[i]) {
          continue;
        }
        auto piece = aStage.candidateLane(CandidateLaneType_Large).pieces()[order[i]];

        auto func = [&](int x, int y) {
          piece.setPos(Vector2i(x, y));
          PieceWithTurn p(piece, t);
          if (!p.collides(bakingPieces) && !p.collides(reservedPieces)) {
            reservedPieces.push_back(p);
            putPieceCount++;
            isUsed[i] = true;
            didPut = true;
          }
        };
        if (arePiecesHorizontal) {
          for (int y = 0; !didPut && y < Parameter::OvenHeight - piece.height() + 1; y++) {
            for (int x = 0; !didPut && x < Parameter::OvenWidth - piece.width() + 1; x++) {
              func(x, y);
            }
          }
        } else {
          for (int x = 0; !didPut && x < Parameter::OvenWidth - piece.width() + 1; x++) {
            for (int y = 0; !didPut && y < Parameter::OvenHeight - piece.height() + 1; y++) {
              func(x, y);
            }
          }
        }
      }
    }
  }

  // キューの先頭にある大きいクッキーを置く。
  if (reservedPieces.size() && reservedPieces.front().turn == aStage.turn()) {
    auto piece = reservedPieces.front().piece;
    reservedPieces.clear();

    for (int i = 0; i < Parameter::CandidatePieceCount; i++) {
      auto& p = aStage.candidateLane(CandidateLaneType_Large).pieces()[i];
      if (p.width() == piece.width() && p.height() == piece.height() &&
          p.requiredHeatTurnCount() == piece.requiredHeatTurnCount() && p.score() == piece.score()) {
        return Action::Put(CandidateLaneType_Large, i, piece.pos());
      }
    }
  }

  // 小さいクッキーを大きいクッキーと重ならない場所に置く。
  {
    // よりスコアが高いクッキーを先に試すように並び替える。
    std::vector<int> order(Parameter::CandidatePieceCount);
    std::iota(begin(order), end(order), 0);
    sort(order.begin(), order.end(), [&aStage](int a, int b) {
      auto pieceA = aStage.candidateLane(CandidateLaneType_Small).pieces()[a];
      auto pieceB = aStage.candidateLane(CandidateLaneType_Small).pieces()[b];
      int scoreA = pieceA.score();
      int scoreB = pieceB.score();
      return scoreA != scoreB ? scoreA > scoreB : a < b;
    });

    for (int i = 0; i < Parameter::CandidatePieceCount; i++) {
      auto piece = aStage.candidateLane(CandidateLaneType_Small).pieces()[order[i]];

      if (arePiecesHorizontal) {
        for (int y = 0; y < Parameter::OvenHeight - piece.height() + 1; y++) {
          for (int x = 0; x < Parameter::OvenWidth - piece.width() + 1; x++) {
            Vector2i pos = Vector2i(x, y);
            piece.setPos(pos);
            if (aStage.oven().isAbleToPut(piece, pos) &&
                !PieceWithTurn(piece, aStage.turn()).collides(reservedPieces)) {
              return Action::Put(CandidateLaneType_Small, order[i], pos);
            }
          }
        }
      } else {
        for (int x = 0; x < Parameter::OvenWidth - piece.width() + 1; x++) {
          for (int y = 0; y < Parameter::OvenHeight - piece.height() + 1; y++) {
            Vector2i pos = Vector2i(x, y);
            piece.setPos(pos);
            if (aStage.oven().isAbleToPut(piece, pos) &&
                !PieceWithTurn(piece, aStage.turn()).collides(reservedPieces)) {
              return Action::Put(CandidateLaneType_Small, order[i], pos);
            }
          }
        }
      }
    }
  }

  return Action::Wait();
}

void Answer::finalize(const Stage& aStage) {}

}  // namespace hpc