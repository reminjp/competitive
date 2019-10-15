#include "Answer.hpp"
#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>

constexpr int INF = 1e5;

namespace hpc {
Random random(RandomSeed::DefaultSeed());
int stage_index;
std::array<std::queue<int>, Parameter::MaxTurtleCount> routes;

inline int distance(Point a, Point b) {
  return (a.x < b.x ? b.x - a.x : a.x - b.x) + (a.y < b.y ? b.y - a.y : a.y - b.y);
}

// ゲーム開始前
Answer::Answer() { stage_index = 0; }
// ゲーム終了後
Answer::~Answer() {}

// 各ステージ開始前
void Answer::initialize(const Stage& aStage) {
  const auto& turtle_poss = aStage.turtlePositions();
  int turtle_count = turtle_poss.count();
  const auto& foods = aStage.foods();
  int food_count = foods.count();

  std::vector<Point> food_poss(food_count);
  std::vector<int> food_heights(food_count);
  for (int i = 0; i < food_count; ++i) {
    food_poss[i] = foods[i].pos();
    food_heights[i] = foods[i].height();
  }

  for (auto& route : routes) {
    while (!route.empty()) route.pop();
  }

  std::vector<int> indices(turtle_count), turns(turtle_count, 0), next_turns(turtle_count), nearest_turtles;
  std::vector<bool> is_eaten(food_count);
  std::vector<Point> poss(turtle_poss.begin(), turtle_poss.end());
  std::iota(indices.begin(), indices.end(), 0);
  nearest_turtles.reserve(turtle_count);

  for (int i = 0; i < food_count; ++i) {
    int nearest_food_index = 0, nearest_food_turn = INF;
    nearest_turtles.clear();

    for (int fi = 0; fi < food_count; ++fi) {
      if (is_eaten[fi]) continue;
      for (int ti = 0; ti < turtle_count; ++ti) next_turns[ti] = turns[ti] + distance(poss[ti], food_poss[fi]);
      std::sort(indices.begin(), indices.end(), [&next_turns](int a, int b) { return next_turns[a] < next_turns[b]; });

      int max_turn = 0;
      for (auto it = indices.begin(); it != indices.begin() + food_heights[fi]; ++it) {
        if (next_turns[*it] > max_turn) max_turn = next_turns[*it];
      }

      if (max_turn < nearest_food_turn) {
        nearest_food_index = fi;
        nearest_food_turn = max_turn;
        nearest_turtles.resize(food_heights[fi]);
        std::copy(indices.begin(), indices.begin() + food_heights[fi], nearest_turtles.begin());
      }
    }

    is_eaten[nearest_food_index] = true;
    for (int ti : nearest_turtles) {
      routes[ti].push(nearest_food_index);
      turns[ti] = nearest_food_turn;
      poss[ti] = food_poss[nearest_food_index];
    }
  }
}

// 各ターン
void Answer::setActions(const Stage& aStage, Actions& aActions) {
  const auto& turtle_poss = aStage.turtlePositions();
  int turtle_count = turtle_poss.count();
  for (int turtle_index = 0; turtle_index < turtle_count; ++turtle_index) {
    auto turtle_pos = turtle_poss[turtle_index];
    Point target_food_pos(INF, INF);

    while (!routes[turtle_index].empty()) {
      const auto& food = aStage.foods()[routes[turtle_index].front()];
      if (food.isEaten()) {
        routes[turtle_index].pop();
      } else {
        target_food_pos = food.pos();
        break;
      }
    }
    if (routes[turtle_index].empty()) {
      for (const auto& food : aStage.foods()) {
        if (!food.isEaten() && distance(turtle_pos, food.pos()) < distance(turtle_pos, target_food_pos)) {
          target_food_pos = food.pos();
        }
      }
    }

    if (turtle_pos.x < target_food_pos.x) {
      aActions.add(Action_MoveRight);
    } else if (turtle_pos.x > target_food_pos.x) {
      aActions.add(Action_MoveLeft);
    } else if (turtle_pos.y < target_food_pos.y) {
      aActions.add(Action_MoveDown);
    } else if (turtle_pos.y > target_food_pos.y) {
      aActions.add(Action_MoveUp);
    } else {
      aActions.add(Action_Wait);
    }
  }
}

// 各ステージ終了後
void Answer::finalize(const Stage& aStage) { ++stage_index; }

}  // namespace hpc
