#include "Answer.hpp"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>

constexpr int INF = 1e5;
constexpr double TIME_LIMIT_SECS = 60.0 - 1.0;

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
std::vector<std::vector<int>> routes(Parameter::MaxTurtleCount);

// マンハッタン距離
inline int distance(Point a, Point b) { return Math::Abs(b.x - a.x) + Math::Abs(b.y - a.y); }

// ゲーム開始前
Answer::Answer() {
  timer = ::Timer();
  stage_index = 0;
  for (auto& route : routes) route.reserve(Parameter::MaxFoodCount);
}
// ゲーム終了後
Answer::~Answer() {}

// 各ステージ開始前
void Answer::initialize(const Stage& aStage) {
  const auto& turtle_poss = aStage.turtlePositions();
  int turtle_count = turtle_poss.count();
  const auto& foods = aStage.foods();
  int food_count = foods.count();

  double stage_begin_secs = timer.ElapsedSecs();
  double stage_end_secs = stage_begin_secs + (TIME_LIMIT_SECS - stage_begin_secs) /
                                                 (Parameter::GameStageCount - stage_index) *
                                                 (0.5 + 0.5 * ((stage_index + 1) / Parameter::GameStageCount));

  for (auto& route : routes) route.clear();

  std::vector<int> order(food_count);
  std::iota(order.begin(), order.end(), 0);
  std::sort(order.begin(), order.end(), [&foods](int a, int b) { return foods[a].pos().x < foods[b].pos().x; });

  std::vector<int> indices(turtle_count), turns(turtle_count);
  std::vector<Point> poss(turtle_count);

  int cost = INF;
  int iteration = 0;
  while (timer.ElapsedSecs() < stage_end_secs) {
    iteration++;
    int l = random.randTerm(food_count - 1);
    int r = random.randMinTerm(l + 2, food_count + 1);
    std::reverse(order.begin() + l, order.begin() + r);

    int next_cost = INF;
    {
      std::iota(indices.begin(), indices.end(), 0);
      std::fill(turns.begin(), turns.end(), 0);
      std::copy(turtle_poss.begin(), turtle_poss.end(), poss.begin());
      for (int i : order) {
        auto p = foods[i].pos();
        std::sort(indices.begin(), indices.end(), [&turns, &poss, &p](int a, int b) {
          return turns[a] + distance(poss[a], p) < turns[b] + distance(poss[b], p);
        });
        for (int j = 0, h = foods[i].height(); j < h; j++) {
          turns[indices[j]] += distance(poss[indices[j]], p);
          poss[indices[j]] = p;
        }
      }
      next_cost = *std::max_element(turns.begin(), turns.end());
    }

    if (next_cost <= cost) {
      cost = next_cost;
    } else {
      std::reverse(order.begin() + l, order.begin() + r);
    }
  }
  // std::cerr << stage_index << ' ' << iteration << std::endl;

  std::iota(indices.begin(), indices.end(), 0);
  std::fill(turns.begin(), turns.end(), 0);
  std::copy(turtle_poss.begin(), turtle_poss.end(), poss.begin());
  for (int i : order) {
    auto p = foods[i].pos();
    std::sort(indices.begin(), indices.end(), [&turns, &poss, &p](int a, int b) {
      return turns[a] + distance(poss[a], p) < turns[b] + distance(poss[b], p);
    });
    for (int j = 0, h = foods[i].height(); j < h; j++) {
      routes[indices[j]].push_back(i);
      turns[indices[j]] += distance(poss[indices[j]], p);
      poss[indices[j]] = p;
    }
  }
}

// 各ターン
void Answer::setActions(const Stage& aStage, Actions& aActions) {
  for (int turtle_index = 0; turtle_index < aStage.turtlePositions().count(); turtle_index++) {
    auto turtle_pos = aStage.turtlePositions()[turtle_index];
    Point target_food_pos;
    bool should_wait = true;

    for (size_t i = 0; i < routes[turtle_index].size(); i++) {
      const auto& food = aStage.foods()[routes[turtle_index][i]];
      if (!food.isEaten()) {
        target_food_pos = food.pos();
        should_wait = false;
        break;
      }
    }

    if (should_wait) {
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
void Answer::finalize(const Stage& aStage) { stage_index++; }

}  // namespace hpc
