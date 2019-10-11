#include "Answer.hpp"
#include <ctime>
#include <vector>

constexpr int TIME_LIMIT = 60 * 1000;

class Timer {
 public:
  Timer() : time_begin(std::clock()) {}
  int Elapsed() { return 1000 * (std::clock() - time_begin) / CLOCKS_PER_SEC; }

 private:
  std::clock_t time_begin;
};

namespace hpc {

inline int distance(Point a, Point b) { return Math::Abs(b.x - a.x) + Math::Abs(b.y - a.y); }

Random random(RandomSeed::DefaultSeed());
::Timer timer;
int stage_index;
std::vector<int> route;

Answer::Answer() {
  timer = ::Timer();
  stage_index = 0;
}

Answer::~Answer() {}

void Answer::initialize(const Stage& aStage) {
  const auto& foods = aStage.foods();
  int food_count = foods.count();

  route = std::vector<int>(aStage.foods().count());
  for (int i = 0; i < food_count; i++) route[i] = i;

  int length = 0;
  for (int i = 0; i < food_count; i++) {
    length += distance(foods[route[i]].pos(), foods[route[(i + 1) % food_count]].pos());
  }

  while (timer.Elapsed() + 20 < TIME_LIMIT / Parameter::GameStageCount * (stage_index + 1)) {
    int a1 = random.randTerm(food_count);
    int b1;
    do {
      b1 = random.randTerm(food_count);
      if (b1 < a1) b1 += food_count;
    } while (b1 - a1 < 2);
    int a2 = a1 + 1, b2 = b1 + 1;

    int delta_length = 0;
    delta_length -= distance(foods[route[a1 % food_count]].pos(), foods[route[a2 % food_count]].pos());
    delta_length -= distance(foods[route[b1 % food_count]].pos(), foods[route[b2 % food_count]].pos());
    delta_length += distance(foods[route[a1 % food_count]].pos(), foods[route[b1 % food_count]].pos());
    delta_length += distance(foods[route[a2 % food_count]].pos(), foods[route[b2 % food_count]].pos());

    if (delta_length < 0) {
      length += delta_length;
      for (int i = a2, j = b1; i < j; i++, j--) {
        int t = route[i % food_count];
        route[i % food_count] = route[j % food_count];
        route[j % food_count] = t;
      }
    }
  }
}

void Answer::setActions(const Stage& aStage, Actions& aActions) {
  Point targetFoodPosition;
  for (int i = 0; i < aStage.foods().count(); i++) {
    const auto& food = aStage.foods()[route[i]];
    if (!food.isEaten()) {
      targetFoodPosition = food.pos();
      break;
    }
  }

  for (Point turtlePosition : aStage.turtlePositions()) {
    if (turtlePosition.x < targetFoodPosition.x) {
      aActions.add(Action_MoveRight);
    } else if (turtlePosition.x > targetFoodPosition.x) {
      aActions.add(Action_MoveLeft);
    } else if (turtlePosition.y < targetFoodPosition.y) {
      aActions.add(Action_MoveDown);
    } else if (turtlePosition.y > targetFoodPosition.y) {
      aActions.add(Action_MoveUp);
    } else {
      aActions.add(Action_Wait);
    }
  }
}

void Answer::finalize(const Stage& aStage) { stage_index++; }

}  // namespace hpc
