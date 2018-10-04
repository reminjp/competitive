#include "Answer.hpp"
#include <algorithm>
#include <utility>

namespace hpc {

Answer::Answer() {}

Answer::~Answer() {}

void Answer::init(const Stage& aStage) {}

Action Answer::decideNextAction(const Stage& aStage) {
  Array<std::pair<CandidateLaneType, int>, 2 * Parameter::CandidatePieceCount> pieceIndices;
  for (int i = 0, count = aStage.candidateLane(CandidateLaneType_Small).pieces().count(); i < count; i++) {
    pieceIndices.add({CandidateLaneType_Small, i});
  }
  for (int i = 0, count = aStage.candidateLane(CandidateLaneType_Large).pieces().count(); i < count; i++) {
    pieceIndices.add({CandidateLaneType_Large, i});
  }

  sort(pieceIndices.begin(), pieceIndices.end(),
       [&aStage](const std::pair<CandidateLaneType, int>& a, const std::pair<CandidateLaneType, int>& b) {
         auto pieceA = aStage.candidateLane(a.first).pieces()[a.second];
         auto pieceB = aStage.candidateLane(b.first).pieces()[b.second];
         int areaA = pieceA.height() * pieceA.width();
         int areaB = pieceB.height() * pieceB.width();
         int timeSpaceA = pieceA.requiredHeatTurnCount() * areaA;
         int timeSpaceB = pieceB.requiredHeatTurnCount() * areaB;
         double valueA = (double)pieceA.score() / timeSpaceA;
         double valueB = (double)pieceB.score() / timeSpaceB;
         return valueA != valueB
                    ? valueA > valueB
                    : timeSpaceA != timeSpaceB ? timeSpaceA < timeSpaceB
                                               : areaA != areaB ? areaA < areaB : pieceA.height() < pieceB.height();
       });

  for (auto& e : pieceIndices) {
    CandidateLaneType laneType = e.first;
    int pieceIndex = e.second;
    const auto& piece = aStage.candidateLane(laneType).pieces()[pieceIndex];

    Vector2i pos;
    for (pos.y = 0; pos.y < aStage.oven().height() - piece.height() + 1; pos.y++) {
      for (pos.x = 0; pos.x < aStage.oven().width() - piece.width() + 1; pos.x++) {
        if (aStage.oven().isAbleToPut(piece, pos)) {
          return Action::Put(laneType, pieceIndex, pos);
        }
      }
    }
  }

  return Action::Wait();
}

void Answer::finalize(const Stage& aStage) {}

}  // namespace hpc
