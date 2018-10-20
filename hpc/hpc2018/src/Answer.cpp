#include "Answer.hpp"
#include <algorithm>

namespace hpc {

Answer::Answer() {}

Answer::~Answer() {}

void Answer::init(const Stage& aStage) {}

Action Answer::decideNextAction(const Stage& aStage) {
  // オーブンにある大きいクッキーが焼きあがるまでの時間を取得する。
  int minRestRequiredHeatTurnCount = Parameter::GameTurnLimit;
  for (auto piece : aStage.oven().bakingPieces()) {
    if (piece.width() + piece.height() >= Parameter::MinLargePieceSampleEdgeLength) {
      minRestRequiredHeatTurnCount = Math::Min(minRestRequiredHeatTurnCount, piece.restRequiredHeatTurnCount());
    }
  }

  bool gameWillEnd = true;

  // 大きいクッキーを左上から詰めて置く。
  {
    // 試すクッキーの順番を変える。
    Array<int, Parameter::CandidatePieceCount> order;
    for (int i = 0; i < order.maxCount(); i++) order.add(i);
    std::sort(order.begin(), order.end(), [&aStage, minRestRequiredHeatTurnCount](int a, int b) {
      auto pieceA = aStage.candidateLane(CandidateLaneType_Large).pieces()[a];
      auto pieceB = aStage.candidateLane(CandidateLaneType_Large).pieces()[b];
      auto sizeA = pieceA.height() * pieceA.width();
      auto sizeB = pieceB.height() * pieceB.width();
      return sizeA != sizeB ? sizeA > sizeB : a < b;
    });

    for (int i = 0; i < Parameter::CandidatePieceCount; i++) {
      auto& piece = aStage.candidateLane(CandidateLaneType_Large).pieces()[order[i]];

      // ゲーム終了までに焼き終わらないクッキーを置かない。
      if (piece.requiredHeatTurnCount() >= Parameter::GameTurnLimit - aStage.turn()) {
        continue;
      }
      gameWillEnd = false;

      for (int y = 0; y <= Parameter::OvenHeight - piece.height(); y++) {
        Vector2i pos;
        pos = Vector2i(0, y);
        if (aStage.oven().isAbleToPut(piece, pos)) {
          return Action::Put(CandidateLaneType_Large, order[i], pos);
        }
        pos = Vector2i(Parameter::OvenWidth - piece.width(), y);
        if (aStage.oven().isAbleToPut(piece, pos)) {
          return Action::Put(CandidateLaneType_Large, order[i], pos);
        }
      }

      for (int x = 0; x <= Parameter::OvenWidth - piece.width(); x++) {
        Vector2i pos;
        pos = Vector2i(x, 0);
        if (aStage.oven().isAbleToPut(piece, pos)) {
          return Action::Put(CandidateLaneType_Large, order[i], pos);
        }
        pos = Vector2i(x, Parameter::OvenHeight - piece.height());
        if (aStage.oven().isAbleToPut(piece, pos)) {
          return Action::Put(CandidateLaneType_Large, order[i], pos);
        }
      }
    }
  }

  // 小さいクッキーを大きいクッキーと重ならない場所に置く。
  {
    // 試すクッキーの順番を変える。
    Array<int, Parameter::CandidatePieceCount> order;
    for (int i = 0; i < order.maxCount(); i++) order.add(i);
    std::sort(order.begin(), order.end(), [&aStage](int a, int b) {
      auto pieceA = aStage.candidateLane(CandidateLaneType_Small).pieces()[a];
      auto pieceB = aStage.candidateLane(CandidateLaneType_Small).pieces()[b];
      auto turnA = pieceA.requiredHeatTurnCount();
      auto turnB = pieceB.requiredHeatTurnCount();
      auto scoreA = pieceA.score();
      auto scoreB = pieceB.score();
      return turnA != turnB ? turnA > turnB : scoreA != scoreB ? scoreA > scoreB : a < b;
    });

    for (int i = 0; i < Parameter::CandidatePieceCount; i++) {
      auto& piece = aStage.candidateLane(CandidateLaneType_Small).pieces()[order[i]];

      // 大きいクッキーの焼きあがりを待つ。
      if (!gameWillEnd && piece.requiredHeatTurnCount() > minRestRequiredHeatTurnCount) {
        continue;
      }

      for (int y = 0; y <= Parameter::OvenHeight - piece.height(); y++) {
        for (int x = 0; x <= Parameter::OvenWidth - piece.width(); x++) {
          Vector2i pos = Vector2i(x, y);
          if (aStage.oven().isAbleToPut(piece, pos)) {
            return Action::Put(CandidateLaneType_Small, order[i], pos);
          }
        }
      }
    }
  }

  return Action::Wait();
}

void Answer::finalize(const Stage& aStage) {}

}  // namespace hpc
