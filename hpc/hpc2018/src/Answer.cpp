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

std::vector<PieceWithTurn> reservedPieces;

Answer::Answer() {}

Answer::~Answer() {}

void Answer::init(const Stage& aStage) { reservedPieces.clear(); }

Action Answer::decideNextAction(const Stage& aStage) {
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
      int sizeA = pieceA.requiredHeatTurnCount() * pieceA.height() * pieceA.width();
      int sizeB = pieceB.requiredHeatTurnCount() * pieceB.height() * pieceB.width();
      return sizeA != sizeB ? sizeA < sizeB : a < b;
    });

    // 大きいクッキーを左上から詰めて置く。
    std::vector<bool> isUsed(Parameter::CandidatePieceCount);
    for (int t = aStage.turn(); t <= aStage.turn() + Parameter::GameTurnLimit; t++) {
      bool didPut = false;

      for (int i = 0; !didPut && i < Parameter::CandidatePieceCount; i++) {
        if (isUsed[i]) {
          continue;
        }
        auto piece = aStage.candidateLane(CandidateLaneType_Large).pieces()[order[i]];

        for (int y = 0; !didPut && y < Parameter::OvenHeight - piece.height() + 1; y++) {
          for (int x = 0; !didPut && x < Parameter::OvenWidth - piece.width() + 1; x++) {
            piece.setPos(Vector2i(x, y));
            PieceWithTurn p(piece, t);
            if (!p.collides(bakingPieces) && !p.collides(reservedPieces)) {
              reservedPieces.push_back(p);
              isUsed[i] = true;
              didPut = true;
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

    for (int i = 0, count = aStage.candidateLane(CandidateLaneType_Large).pieces().count(); i < count; i++) {
      auto& p = aStage.candidateLane(CandidateLaneType_Large).pieces()[i];
      if (p.width() == piece.width() && p.height() == piece.height() &&
          p.requiredHeatTurnCount() == piece.requiredHeatTurnCount() && p.score() == piece.score()) {
        return Action::Put(CandidateLaneType_Large, i, piece.pos());
      }
    }
  }

  // 小さいクッキーを大きいクッキーと重ならない場所に置く。
  for (int i = 0, count = aStage.candidateLane(CandidateLaneType_Small).pieces().count(); i < count; i++) {
    auto piece = aStage.candidateLane(CandidateLaneType_Small).pieces()[i];

    Vector2i pos;
    for (pos.y = 0; pos.y < Parameter::OvenHeight - piece.height() + 1; pos.y++) {
      for (pos.x = 0; pos.x < Parameter::OvenWidth - piece.width() + 1; pos.x++) {
        piece.setPos(pos);
        if (aStage.oven().isAbleToPut(piece, pos) && !PieceWithTurn(piece, aStage.turn()).collides(reservedPieces)) {
          return Action::Put(CandidateLaneType_Small, i, pos);
        }
      }
    }
  }

  return Action::Wait();
}

void Answer::finalize(const Stage& aStage) {}

}  // namespace hpc
