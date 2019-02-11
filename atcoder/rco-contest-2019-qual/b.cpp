#include <bits/stdc++.h>
using namespace std;

const int TIME_LIMIT = 2000;

class timer {
 public:
  timer() : time_begin(clock()) {}
  int elapsed() { return (int)1000 * (clock() - time_begin) / CLOCKS_PER_SEC; }

 private:
  clock_t time_begin;
};

using vector2i = pair<int, int>;
#define y(v) ((v).first)
#define x(v) ((v).second)

const vector2i d[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
  timer t;
  srand(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(n));
  for (auto &e : a) {
    for (auto &ee : e) {
      cin >> ee;
    }
  }

  vector<pair<int, vector2i>> answer;
  int score = 0;
  while (t.elapsed() < TIME_LIMIT - 20) {
    vector<pair<int, vector2i>> next_answer;
    int next_score = 0;

    vector<vector<int>> updated_a = a;
    priority_queue<pair<int, vector2i>> adjacent_poses;
    vector<vector<bool>> visited(n, vector<bool>(n));

    vector<vector2i> start_poses(50);
    for (auto &e : start_poses) {
      e = {rand() % n, rand() % n};
      adjacent_poses.push({10, e});
      visited[y(e)][x(e)] = true;
    }

    while (next_answer.size() < m - start_poses.size()) {
      auto pos = adjacent_poses.top().second;
      adjacent_poses.pop();

      if (9 - updated_a[y(pos)][x(pos)] > (m - start_poses.size()) - next_answer.size()) break;
      for (int i = 9 - updated_a[y(pos)][x(pos)]; i > 0; i--) {
        next_answer.push_back({1, pos});
      }
      updated_a[y(pos)][x(pos)] = 9;
      next_score += 9;

      for (int i = 0; i < 4; i++) {
        vector2i next_pos = {y(pos) + y(d[i]), x(pos) + x(d[i])};
        if (!(0 <= y(next_pos) && y(next_pos) < n && 0 <= x(next_pos) && x(next_pos) < n)) continue;
        if (visited[y(next_pos)][x(next_pos)]) continue;
        adjacent_poses.push({a[y(next_pos)][x(next_pos)], next_pos});
        visited[y(next_pos)][x(next_pos)] = true;
      }
    }
    for (auto e : start_poses) {
      next_answer.push_back({2, e});
    }

    if (next_score > score) {
      score = next_score;
      answer = next_answer;
    }
  }

  for (auto e : answer) {
    cout << e.first << " " << y(e.second) << " " << x(e.second) << endl;
  }
  cerr << "score (limit): " << score << endl;
  cerr << "time: " << t.elapsed() << endl;
}
