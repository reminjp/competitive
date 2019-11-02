#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const string i_to_c = "UDLR";
int c_to_i[256];

struct Robot {
  int y, x;
  char c;
};

struct Cell {
  bool is_block, is_arrow;
  int arrow;
  int user_count;
};

struct Point {
  int y, x;
};

int N, M, B, gy, gx;
vector<Robot> robots;
vector<vector<Cell>> grid;

bool simulate_robot(int index, vector<Point>& route) {
  int y = robots[index].y, x = robots[index].x, d = c_to_i[robots[index].c];
  while (true) {
    if (y == gy && x == gx) return true;
    if (grid[y][x].is_block) return false;
    if (grid[y][x].is_arrow && grid[y][x].arrow != d) {
      route.push_back(Point{y, x});
      d = grid[y][x].arrow;
    }
    y = (N + y + dy[d]) % N;
    x = (N + x + dx[d]) % N;
  }
}

int simulate(const vector<vector<Cell>>& grid) {
  vector<bool> is_robot_reached(M);
  vector<vector<bool>> is_cell_visited(N, vector<bool>(N));

  for (int i = 0; i < M; i++) {
    vector<vector<vector<bool>>> s(N, vector<vector<bool>>(N, vector<bool>(4)));

    int y = robots[i].y, x = robots[i].x, d = c_to_i[robots[i].c];
    while (true) {
      if (s[y][x][d]) break;
      s[y][x][d] = true;
      is_cell_visited[y][x] = true;
      if (y == gy && x == gx) {
        is_robot_reached[i] = true;
        break;
      }
      if (grid[y][x].is_block) break;
      if (grid[y][x].is_arrow) {
        d = grid[y][x].arrow;
      }
      y = (N + y + dy[d]) % N;
      x = (N + x + dx[d]) % N;
    }
  }

  int score = 0;
  for (auto e : is_robot_reached) {
    if (e) score += 1000;
  }
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (grid[y][x].is_arrow) score -= 10;
      if (is_cell_visited[y][x]) score += 1;
    }
  }
  return score;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < 4; i++) c_to_i[i_to_c[i]] = i;

  // input
  cin >> N >> M >> B >> gy >> gx;
  robots.resize(M);
  grid.resize(N);
  for (auto& e : grid) e.resize(N);

  for (int i = 0; i < M; i++) {
    cin >> robots[i].y >> robots[i].x >> robots[i].c;
  }
  for (int i = 0; i < B; i++) {
    int by, bx;
    cin >> by >> bx;
    grid[by][bx].is_block = true;
  }

  // solve
  queue<Point> q;
  q.push(Point{gy, gx});
  while (!q.empty()) {
    int y = q.front().y, x = q.front().x;
    q.pop();
    for (int d = 0; d < 4; d++) {
      for (int i = 1;; i++) {
        int yt = (N + y - i * dy[d]) % N, xt = (N + x - i * dx[d]) % N;
        if (grid[yt][xt].is_block || grid[yt][xt].is_arrow) break;
        grid[yt][xt].is_arrow = true;
        grid[yt][xt].arrow = d;
        q.push(Point{yt, xt});
      }
    }
  }

  for (int i = 0; i < M; i++) {
    vector<Point> r;
    simulate_robot(i, r);
    for (auto e : r) grid[e.y][e.x].user_count++;
  }
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (grid[y][x].user_count == 0) grid[y][x].is_arrow = false;
    }
  }

  int score = simulate(grid);
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (!grid[y][x].is_arrow) continue;
      grid[y][x].is_arrow = false;
      int s = simulate(grid);
      if (s > score) {
        score = s;
      } else {
        grid[y][x].is_arrow = true;
      }
    }
  }

  // output
  vector<tuple<int, int, char>> output;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (grid[y][x].is_arrow) output.push_back(make_tuple(y, x, i_to_c[grid[y][x].arrow]));
    }
  }
  cout << output.size() << '\n';
  for (const auto& e : output) cout << get<0>(e) << ' ' << get<1>(e) << ' ' << get<2>(e) << '\n';
  cout << flush;
}
