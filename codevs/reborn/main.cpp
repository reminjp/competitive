// compile: g++ -std=c++11 -O2 main.cpp
#include <chrono>
#include <cstring>
#include <deque>
#include <iostream>
#include <random>
#include <utility>
#include <vector>
using namespace std;

const string NAME = "mohuhu";
constexpr int SEARCH_TURN_COUNT = 20;
constexpr int SEARCH_TIME_LIMIT_PER_TURN = 15000;

constexpr int WIDTH = 10;
constexpr int HEIGHT = 16;
constexpr int PACK_SIZE = 2;
constexpr int TURN_COUNT = 500;
constexpr int SKILL_COST = 80;
constexpr int ANNIHILATION_SUM = 10;
constexpr int OBSTACLE_BLOCK = ANNIHILATION_SUM + 1;
constexpr int EMPTY_BLOCK = 0;

class Timer {
 public:
  Timer() : time_begin(now()) {}
  int elapsed() { return chrono::duration_cast<chrono::milliseconds>(now() - time_begin).count(); }

 private:
  chrono::system_clock::time_point time_begin;
  static chrono::system_clock::time_point now() { return chrono::system_clock::now(); }
};

struct Pack {
  int blocks[PACK_SIZE][PACK_SIZE];

  Pack() { fill(this->blocks[0], this->blocks[PACK_SIZE + 1], EMPTY_BLOCK); }

  void rotate() {
    int t[PACK_SIZE][PACK_SIZE];
    memcpy(t, this->blocks, PACK_SIZE * PACK_SIZE);
    for (int i = PACK_SIZE - 1; i >= 0; i--) {
      for (int j = 0; j < PACK_SIZE; j++) {
        this->blocks[i][j] = t[j][PACK_SIZE - 1 - i];
      }
    }
  }

  void rotate(int n) {
    n = (n % 4 + 4) % 4;
    for (int i = 0; i < n; i++) {
      this->rotate();
    }
  }

  Pack& operator=(const Pack& p) & {
    for (int i = 0; i < PACK_SIZE; i++) {
      for (int j = 0; j < PACK_SIZE; j++) {
        this->blocks[i][j] = p.blocks[i][j];
      }
    }
  }
};

ostream& operator<<(ostream& os, const Pack& p) {
  for (int i = PACK_SIZE - 1; i >= 0; i--) {
    for (int j = 0; j < PACK_SIZE; j++) {
      os << p.blocks[i][j] << (j == PACK_SIZE - 1 ? '\n' : ' ');
    }
  }
  os << "END\n";
  return os;
}

istream& operator>>(istream& is, Pack& p) {
  for (int i = PACK_SIZE - 1; i >= 0; i--) {
    for (int j = 0; j < PACK_SIZE; j++) {
      is >> p.blocks[i][j];
    }
  }
  string _;
  is >> _;
  return is;
}

struct Field {
  int blocks[HEIGHT + PACK_SIZE + 1][WIDTH];

  Field() { fill(this->blocks[0], this->blocks[HEIGHT + PACK_SIZE + 1], EMPTY_BLOCK); }

  Field(const Field& f) {
    for (int i = 0; i < HEIGHT + PACK_SIZE + 1; i++) {
      for (int j = 0; j < WIDTH; j++) {
        this->blocks[i][j] = f.blocks[i][j];
      }
    }
  }

  int update() {
    int chain = 0;
    int t[HEIGHT + PACK_SIZE + 1][WIDTH];
    bool b[HEIGHT + PACK_SIZE + 1][WIDTH];
    for (bool iterate = true; iterate;) {
      iterate = false;
      // Falling blocks
      copy(this->blocks[0], this->blocks[HEIGHT + PACK_SIZE + 1], t[0]);
      fill(this->blocks[0], this->blocks[HEIGHT + PACK_SIZE + 1], EMPTY_BLOCK);
      for (int j = 0; j < WIDTH; j++) {
        for (int i = 0, h = 0; i < HEIGHT + PACK_SIZE + 1; i++) {
          if (t[i][j] != EMPTY_BLOCK) {
            this->blocks[h][j] = t[i][j];
            h++;
          }
        }
      }
      // Annihilating blocks
      fill(b[0], b[HEIGHT + PACK_SIZE + 1], false);
      for (int i = 0; i < HEIGHT + PACK_SIZE + 1 - 1; i++) {
        for (int j = 0; j < WIDTH - 1; j++) {
          for (int di = -1; !b[i][j] && di <= 1; di++) {
            for (int dj = -1; !b[i][j] && dj <= 1; dj++) {
              if (!di && !dj || !(0 <= i + di && i + di < HEIGHT + PACK_SIZE + 1 && 0 <= j + dj && j + dj < WIDTH)) {
                continue;
              }
              b[i][j] |= this->blocks[i][j] + this->blocks[i + di][j + dj] == ANNIHILATION_SUM;
            }
          }
        }
      }
      for (int i = 0; i < HEIGHT + PACK_SIZE + 1 - 1; i++) {
        for (int j = 0; j < WIDTH - 1; j++) {
          if (b[i][j]) {
            this->blocks[i][j] = EMPTY_BLOCK;
            iterate = true;
          }
        }
      }
      if (iterate) {
        chain++;
      }
    }
    return chain;
  }

  int useSkill() {
    int count = 0;
    for (int i = 0; i < HEIGHT + PACK_SIZE + 1 - 1; i++) {
      for (int j = 0; j < WIDTH - 1; j++) {
        if (this->blocks[i][j] == ANNIHILATION_SUM / 2) {
          for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
              if (!(0 <= i + di && i + di < HEIGHT + PACK_SIZE + 1 && 0 <= j + dj && j + dj < WIDTH)) {
                continue;
              }
              if (this->blocks[i + di][j + dj] != ANNIHILATION_SUM / 2 && this->blocks[i + di][j + dj] != EMPTY_BLOCK) {
                this->blocks[i + di][j + dj] = EMPTY_BLOCK;
                count++;
              }
            }
          }
        }
      }
    }
    for (int i = 0; i < HEIGHT + PACK_SIZE + 1 - 1; i++) {
      for (int j = 0; j < WIDTH - 1; j++) {
        if (this->blocks[i][j] == ANNIHILATION_SUM / 2) {
          this->blocks[i][j] = EMPTY_BLOCK;
          count++;
        }
      }
    }
    return count;
  }

  void put(Pack pack, int position, int rotation) {
    pack.rotate(rotation);
    for (int i = PACK_SIZE - 1; i >= 0; i--) {
      for (int j = 0; j < PACK_SIZE; j++) {
        this->blocks[HEIGHT + 1 + i][position + j] = pack.blocks[i][j];
      }
    }
  }

  void putObstacleBlocks() {
    for (int j = 0; j < WIDTH; j++) {
      for (int i = HEIGHT + PACK_SIZE + 1 - 2; i >= 0; i--) {
        if (this->blocks[i][j] != EMPTY_BLOCK) {
          this->blocks[i + 1][j] = OBSTACLE_BLOCK;
          break;
        }
      }
    }
  }

  bool isLosing() {
    for (int j = 0; j < WIDTH; j++) {
      if (this->blocks[HEIGHT][j] != EMPTY_BLOCK) return true;
    }
    return false;
  }

  Field& operator=(const Field& f) & {
    for (int i = 0; i < HEIGHT + PACK_SIZE + 1; i++) {
      for (int j = 0; j < WIDTH; j++) {
        this->blocks[i][j] = f.blocks[i][j];
      }
    }
  }
};

bool operator==(const Field& f1, const Field& f2) {
  bool equals = true;
  for (int i = 0; i < HEIGHT + PACK_SIZE + 1; i++) {
    for (int j = 0; j < WIDTH; j++) {
      equals &= f1.blocks[i][j] == f2.blocks[i][j];
    }
  }
  return equals;
}

bool operator!=(const Field& f1, const Field& f2) { return !(f1 == f2); }

ostream& operator<<(ostream& os, const Field& f) {
  for (int i = HEIGHT - 1; i >= 0; i--) {
    for (int j = 0; j < WIDTH; j++) {
      os << f.blocks[i][j] << (j == WIDTH - 1 ? '\n' : ' ');
    }
  }
  os << "END\n";
  return os;
}

istream& operator>>(istream& is, Field& f) {
  for (int i = HEIGHT - 1; i >= 0; i--) {
    for (int j = 0; j < WIDTH; j++) {
      is >> f.blocks[i][j];
    }
  }
  string _;
  is >> _;
  return is;
}

// struct GameTreeNode {
//   GameTreeNode* parent = nullptr;
//   vector<GameTreeNode*> children;
//   int turn;
//   Field field;
//   int position;
//   int rotation;
//   int chain;

//   ~GameTreeNode() {
//     for (auto child : children) delete child;
//   }

//   int evaluate() { return 0; }
// };

mt19937 MT(8410325);
int randInt(int from, int to) {
  uniform_int_distribution<int> rand(from, to - 1);
  return rand(MT);
}

int main() {
  cout << NAME << endl;

  vector<Pack> packs(TURN_COUNT);
  for (auto& pack : packs) {
    cin >> pack;
  }

  deque<pair<int, int>> plan;

  int turn;

  int millitime;
  int obstacleCount;
  int skill;
  int score;
  Field field;

  int enemyObstacleCount;
  int enemyMillitime;
  int enemySkill;
  int enemyScore;
  Field enemyField;

  bool usesSkill;
  int position;
  int rotation;

  for (auto pack : packs) {
    // Input
    cin >> turn;

    cin >> millitime;
    cin >> obstacleCount;
    cin >> skill;
    cin >> score;
    cin >> field;
    if (obstacleCount >= WIDTH) {
      field.putObstacleBlocks();
    }

    cin >> enemyMillitime;
    cin >> enemyObstacleCount;
    cin >> enemySkill;
    cin >> enemyScore;
    cin >> enemyField;
    if (enemyObstacleCount >= WIDTH) {
      enemyField.putObstacleBlocks();
    }

    usesSkill = skill >= SKILL_COST;

    if (!usesSkill) {
      // Update
      if (obstacleCount >= WIDTH || plan.size() < SEARCH_TURN_COUNT / 4) {
        plan.clear();
      }

      // Search
      if (plan.empty()) {
        Timer timer;
        int bestEvaluationScore = 0;
        deque<pair<int, int>> searchedPlan(obstacleCount >= WIDTH ? 1 : SEARCH_TURN_COUNT);
        while (timer.elapsed() <
               (obstacleCount >= WIDTH ? SEARCH_TIME_LIMIT_PER_TURN / 10 : SEARCH_TIME_LIMIT_PER_TURN)) {
          for (auto& e : searchedPlan) {
            e.first = randInt(0, WIDTH - PACK_SIZE + 1);
            e.second = randInt(0, 4);
          }
          Field f(field);
          int evaluationScore = 0;
          for (int i = 0; i < searchedPlan.size(); i++) {
            f.put(packs[turn + i], searchedPlan[i].first, searchedPlan[i].second);
            int chain = f.update();
            if (f.isLosing()) {
              evaluationScore = 0;
              break;
            }
            for (int c = 1; c <= chain; c++) evaluationScore += pow(1.3, i);
          }
          evaluationScore /= 2;

          if (evaluationScore > bestEvaluationScore) {
            bestEvaluationScore = evaluationScore;
            plan = searchedPlan;
          }
        }
      }

      if (!plan.empty()) {
        auto e = plan.front();
        plan.pop_front();
        position = e.first;
        rotation = e.second;
      } else {
        position = randInt(0, WIDTH - PACK_SIZE + 1);
        rotation = randInt(0, 4);
      }
    }

    if (usesSkill) {
      plan.clear();
      cout << 'S' << endl;
    } else {
      cout << position << ' ' << rotation << endl;
    }
  }
}
