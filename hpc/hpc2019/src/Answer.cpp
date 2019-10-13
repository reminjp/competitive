#include "Answer.hpp"
#include <algorithm>
#include <array>
#include <ctime>
#include <iostream>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>

constexpr int INF = 1e5;
constexpr double TIME_LIMIT_SECS = 60.0 - 0.1;

class Timer {
 public:
  Timer() : time_begin(std::clock()) {}
  double ElapsedSecs() { return double(std::clock() - time_begin) / CLOCKS_PER_SEC; }

 private:
  std::clock_t time_begin;
};

namespace hpc {
Random random(RandomSeed::DefaultSeed());
::Timer timer;
int stage_index;
int iteration;
std::array<std::queue<int>, Parameter::MaxTurtleCount> routes;

// マンハッタン距離
inline int distance(const Point& a, const Point& b) {
  return (a.x < b.x ? b.x - a.x : a.x - b.x) + (a.y < b.y ? b.y - a.y : a.y - b.y);
}

// ゲーム開始前
Answer::Answer() {
  timer = ::Timer();
  stage_index = 0;
  iteration = 0;
}
// ゲーム終了後
Answer::~Answer() { std::cerr << "iteration: " << iteration << std::endl; }

// 各ステージ開始前
void Answer::initialize(const Stage& aStage) {
  const auto& turtle_poss = aStage.turtlePositions();
  int turtle_count = turtle_poss.count();
  const auto& foods = aStage.foods();
  int food_count = foods.count();

  double stage_begin_secs = timer.ElapsedSecs();
  double stage_end_secs = stage_begin_secs + (TIME_LIMIT_SECS - stage_begin_secs) /
                                                 (Parameter::GameStageCount - stage_index) *
                                                 (0.4 + 0.6 * ((stage_index + 1) / Parameter::GameStageCount));

  for (auto& route : routes) {
    while (!route.empty()) route.pop();
  }

  int height1_food_count = 0;
  for (const auto& food : foods) {
    if (food.height() == 1) height1_food_count++;
  }

  std::vector<int> order(food_count);
  std::iota(order.begin(), order.end(), 0);
  if (height1_food_count >= food_count * 0.25) {
    std::sort(order.begin(), order.end(), [&foods](int a, int b) { return foods[a].pos().x < foods[b].pos().x; });
  } else {
    Point p(Parameter::StageWidth / 2, Parameter::StageHeight / 2);
    for (int i = 0; i < food_count; ++i) {
      for (int j = i + 1; j < food_count; ++j) {
        if (distance(p, foods[order[i]].pos()) > distance(p, foods[order[j]].pos())) {
          std::swap(order[i], order[j]);
        }
      }
      p = foods[order[i]].pos();
    }
  }

  std::vector<int> indices(turtle_count), turns(turtle_count), next_turns(turtle_count);
  std::vector<Point> poss(turtle_count);
  std::iota(indices.begin(), indices.end(), 0);

  int cost = INF;
  while (timer.ElapsedSecs() < stage_end_secs) {
    iteration++;

    int operation = random.randTerm(3);
    int l = random.randTerm(food_count - 1);
    int r = random.randMinTerm(l + 2, food_count + 1);

    if (operation == 0) {
      std::reverse(order.begin() + l, order.begin() + r);
    } else if (operation == 1) {
      // shift_left
      std::rotate(order.begin() + l, order.begin() + (l + 1), order.begin() + r);
    } else {
      // shift_right
      std::rotate(order.begin() + l, order.begin() + (r - 1), order.begin() + r);
    }

    int next_cost = 0;
    {
      std::fill(turns.begin(), turns.end(), 0);
      std::copy(turtle_poss.begin(), turtle_poss.end(), poss.begin());
      for (int i : order) {
        auto p = foods[i].pos();
        for (int j = 0; j < turtle_count; ++j) next_turns[j] = turns[j] + distance(poss[j], p);
        std::sort(indices.begin(), indices.end(),
                  [&next_turns](int a, int b) { return next_turns[a] < next_turns[b]; });
        for (int j = 0, h = foods[i].height(); j < h; ++j) {
          turns[indices[j]] = next_turns[indices[j]];
          poss[indices[j]] = p;
          if (next_turns[indices[j]] > next_cost) next_cost = next_turns[indices[j]];
        }
        if (next_cost > cost) break;
      }
      next_cost = *std::max_element(turns.begin(), turns.end());
    }

    if (next_cost <= cost) {
      cost = next_cost;
    } else {
      if (operation == 0) {
        std::reverse(order.begin() + l, order.begin() + r);
      } else if (operation == 1) {
        std::rotate(order.begin() + l, order.begin() + (r - 1), order.begin() + r);
      } else {
        std::rotate(order.begin() + l, order.begin() + (l + 1), order.begin() + r);
      }
    }
  }

  std::iota(indices.begin(), indices.end(), 0);
  std::fill(turns.begin(), turns.end(), 0);
  std::copy(turtle_poss.begin(), turtle_poss.end(), poss.begin());
  for (int i : order) {
    auto p = foods[i].pos();
    for (int j = 0; j < turtle_count; ++j) next_turns[j] = turns[j] + distance(poss[j], p);
    std::sort(indices.begin(), indices.end(), [&next_turns](int a, int b) { return next_turns[a] < next_turns[b]; });
    for (int j = 0, h = foods[i].height(); j < h; ++j) {
      routes[indices[j]].push(i);
      turns[indices[j]] = next_turns[indices[j]];
      poss[indices[j]] = p;
    }
  }
}

// 各ターン
void Answer::setActions(const Stage& aStage, Actions& aActions) {
  for (int turtle_index = 0; turtle_index < aStage.turtlePositions().count(); ++turtle_index) {
    auto turtle_pos = aStage.turtlePositions()[turtle_index];
    Point target_food_pos;

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
      aActions.add(Action_Wait);
    } else if (turtle_pos.x < target_food_pos.x) {
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