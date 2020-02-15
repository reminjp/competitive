#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
const string direction_int_to_char = "URDL";
map<char, int> direction_char_to_int;
const int color_to_rotation[] = {0, 1, 3, 2};

struct Point {
  int y, x;
};

struct Command {
  int y, x, d;
};

int paint(const vector<vector<int>> &a, vector<vector<int>> &m, Point &p, int d, int c, bool update = true) {
  int s = 0;
  for (int i = 0; i < 5; i++) {
    Point p2{p.y + dy[d], p.x + dx[d]};
    if (p2.y < 0 || m.size() <= p2.y || p2.x < 0 || m.front().size() <= p2.x) return s;
    p = p2;
    if (m[p.y][p.x] != c) {
      if (a[p.y][p.x] == c) s++;
      if (a[p.y][p.x] == m[p.y][p.x]) s--;
    }
    if (update) m[p.y][p.x] = c;
  }
  return s;
}

int main() {
  for (int i = 0; i < direction_int_to_char.size(); i++) direction_char_to_int[direction_int_to_char[i]] = i;

  int N, M;
  cin >> N >> M;
  vector<vector<int>> a(N, vector<int>(N));
  for (auto &ai : a) {
    for (auto &e : ai) cin >> e;
  }

  vector<Command> r(M);
  vector<vector<int>> m(N, vector<int>(N, -1));
  vector<Point> setup_current_points{{0, 0}, {0, N - 1}, {N - 1, 0}, {N - 1, N - 1}};
  string setup_command = "RDR" + string(6, 'D') + string(6, 'R') + string(6, 'U');
  for (int i = 0; i < M; i++) {
    int c = i % 4;

    if (i / 4 < setup_command.size()) {
      int d = (direction_char_to_int[setup_command[i / 4]] + color_to_rotation[c]) % 4;
      r[i] = Command{setup_current_points[c].y, setup_current_points[c].x, d};
      paint(a, m, setup_current_points[c], d, c);
    } else {
      int y_best = -1, x_best = -1, d_best = -1, s_best = -1;
      for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
          if (m[y][x] != c) continue;
          for (int d = 0; d < 4; d++) {
            Point p{y, x};
            int s = paint(a, m, p, d, c, false);
            if (s > s_best) {
              y_best = y;
              x_best = x;
              d_best = d;
              s_best = s;
            }
          }
        }
      }
      r[i] = Command{y_best, x_best, d_best};
      Point p{y_best, x_best};
      if (d_best != -1) paint(a, m, p, d_best, c);
    }
  }

  for (auto e : r) {
    if (e.d == -1) {
      cout << -1 << '\n';
    } else {
      cout << e.y << ' ' << e.x << ' ' << direction_int_to_char[e.d] << '\n';
    }
  }
  cerr << flush;
}
