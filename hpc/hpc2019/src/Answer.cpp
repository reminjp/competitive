#include "Answer.hpp"
#include <algorithm>
#include <ctime>
#include <numeric>
#include <vector>

constexpr int INF = 1e9;
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

inline int distance(Point a, Point b) { return Math::Abs(b.x - a.x) + Math::Abs(b.y - a.y); }

void optimize_route(const Stage& aStage, const std::vector<Point>& turtle_poss, const std::vector<int> turtle_indices,
                    std::vector<int>& route, double time_limit) {
  if (route.size() == 1) return;
  const auto& foods = aStage.foods();

  int cost = 0;
  for (int i : turtle_indices) cost += distance(turtle_poss[i], foods[route[0]].pos());
  {
    int l = 0;
    for (size_t i = 0; i + 1 < route.size(); i++) {
      l = Math::Max(l, distance(foods[route[i]].pos(), foods[route[i + 1]].pos()));
    }
    cost += l;
  }

  while (timer.ElapsedSecs() < time_limit) {
    int a = random.randTerm((int)route.size() - 1);
    int b = random.randMinTerm(a + 1, (int)route.size());

    int delta_cost = 0;
    if (a == 0) {
      {
        int l = 0;
        for (int i : turtle_indices) l = Math::Max(l, distance(turtle_poss[i], foods[route[a]].pos()));
        delta_cost -= l;
      }
      {
        int l = 0;
        for (int i : turtle_indices) l = Math::Max(l, distance(turtle_poss[i], foods[route[b]].pos()));
        delta_cost += l;
      }
    } else {
      delta_cost -= distance(foods[route[a - 1]].pos(), foods[route[a]].pos());
      delta_cost += distance(foods[route[a - 1]].pos(), foods[route[b]].pos());
    }
    if (b != (int)route.size() - 1) {
      delta_cost -= distance(foods[route[b]].pos(), foods[route[b + 1]].pos());
      delta_cost += distance(foods[route[a]].pos(), foods[route[b + 1]].pos());
    }

    if (delta_cost < 0) {
      cost += delta_cost;
      for (int i = a, j = b; i < j; i++, j--) {
        int t = route[i];
        route[i] = route[j];
        route[j] = t;
      }
    }
  }
}

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
  // HPC_PRINTF("stage %d\n", stage_index);

  // ステージ情報
  const auto& turtle_poss = aStage.turtlePositions();
  int turtle_count = turtle_poss.count();
  const auto& foods = aStage.foods();
  int food_count = foods.count();

  double stage_begin_secs = timer.ElapsedSecs();
  double stage_end_secs =
      stage_begin_secs + (TIME_LIMIT_SECS - stage_begin_secs) / (Parameter::GameStageCount - stage_index);

  // ステージの傾向を計算する
  std::vector<int> height_histogram(turtle_count + 1);
  for (const auto& food : foods) height_histogram[food.height()]++;
  for (int i = 0; i + 1 < turtle_count + 1; i++) height_histogram[i + 1] += height_histogram[i];
  // HPC_PRINTF("%d: %d %d %d\n", stage_index, height_histogram[1], height_histogram[(turtle_count + 1) / 2],
  //            height_histogram.back());

  // 経路を構築する
  // 初期化
  for (auto& route : routes) route.clear();
  std::vector<bool> is_eaten(food_count);
  std::vector<Point> simulated_turtle_poss(turtle_poss.begin(), turtle_poss.end());

  // 高さ1のエサを分担して食べる
  if (height_histogram[1] >= height_histogram.back() / 3) {
    std::vector<int> food_indices;
    food_indices.reserve(height_histogram[1]);
    for (int i = 0; i < food_count; i++) {
      if (!is_eaten[i] && foods[i].height() == 1) food_indices.push_back(i);
    }

    int food_count_per_turtle = ((int)food_indices.size() - 1) / turtle_count + 1;
    for (int turtle_index = 1; turtle_index < turtle_count; turtle_index++) {
      while ((int)routes[turtle_index].size() <= food_count_per_turtle) {
        int nearest_food_index = -1;
        int nearest_food_distance = INF;
        for (int food_index : food_indices) {
          if (is_eaten[food_index]) continue;
          int d = distance(simulated_turtle_poss[turtle_index], foods[food_index].pos());
          if (nearest_food_index == -1 || d < nearest_food_distance) {
            nearest_food_index = food_index;
            nearest_food_distance = d;
          }
        }
        if (nearest_food_index == -1) break;
        is_eaten[nearest_food_index] = true;
        routes[turtle_index].push_back(nearest_food_index);
        simulated_turtle_poss[turtle_index] = foods[nearest_food_index].pos();
      }
    }
  }

  // 低いエサを分担して食べる
  if (height_histogram[turtle_count / 2] >= height_histogram.back() / 2) {
    // カメを左右に分ける
    std::vector<int> sorted_turtle_indices(turtle_count);
    std::iota(sorted_turtle_indices.begin(), sorted_turtle_indices.end(), 0);
    std::sort(sorted_turtle_indices.begin(), sorted_turtle_indices.end(), [&simulated_turtle_poss](int a, int b) {
      return simulated_turtle_poss[a].x < simulated_turtle_poss[b].x;
    });
    std::vector<int> left_turtle_indices(sorted_turtle_indices.begin(),
                                         sorted_turtle_indices.begin() + sorted_turtle_indices.size() / 2);
    std::vector<int> right_turtle_indices(sorted_turtle_indices.begin() + sorted_turtle_indices.size() / 2,
                                          sorted_turtle_indices.end());

    // エサを左右に分ける
    int height = turtle_count / 2;
    std::vector<int> left_food_indices, right_food_indices;
    left_food_indices.reserve(height_histogram[height]);
    right_food_indices.reserve(height_histogram[height]);
    for (int i = 0; i < food_count; i++) {
      if (!is_eaten[i] && foods[i].height() <= height) {
        is_eaten[i] = true;
        if (foods[i].pos().x < Parameter::StageWidth / 2) {
          left_food_indices.push_back(i);
        } else {
          right_food_indices.push_back(i);
        }
      }
    }

    // 経路を最適化する
    if (!left_food_indices.empty()) {
      optimize_route(aStage, simulated_turtle_poss, left_turtle_indices, left_food_indices,
                     stage_begin_secs + (stage_end_secs - stage_begin_secs) * 0.3);
      for (int turtle_index : left_turtle_indices) {
        simulated_turtle_poss[turtle_index] = foods[left_food_indices.back()].pos();
        for (int food_index : left_food_indices) routes[turtle_index].push_back(food_index);
      }
    }
    if (!right_food_indices.empty()) {
      optimize_route(aStage, simulated_turtle_poss, right_turtle_indices, right_food_indices,
                     stage_begin_secs + (stage_end_secs - stage_begin_secs) * 0.6);
      for (int turtle_index : right_turtle_indices) {
        simulated_turtle_poss[turtle_index] = foods[right_food_indices.back()].pos();
        for (int food_index : right_food_indices) routes[turtle_index].push_back(food_index);
      }
    }
  }

  // 高いエサをすべてのカメで食べる
  {
    std::vector<int> food_indices;
    food_indices.reserve(height_histogram[1]);
    for (int i = 0; i < food_count; i++) {
      if (!is_eaten[i]) food_indices.push_back(i);
    }

    if (!food_indices.empty()) {
      std::vector<int> turtle_indices(turtle_count);
      std::iota(turtle_indices.begin(), turtle_indices.end(), 0);

      optimize_route(aStage, simulated_turtle_poss, turtle_indices, food_indices,
                     stage_begin_secs + (stage_end_secs - stage_begin_secs) * 0.9);
      for (int turtle_index : turtle_indices) {
        simulated_turtle_poss[turtle_index] = foods[food_indices.back()].pos();
        for (int food_index : food_indices) routes[turtle_index].push_back(food_index);
      }
    }
  }
}

// 各ターン
void Answer::setActions(const Stage& aStage, Actions& aActions) {
  // HPC_PRINTF("turn %d\n", aStage.turn());

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
