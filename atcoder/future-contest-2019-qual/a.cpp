#include <bits/stdc++.h>
using namespace std;

constexpr int time_limit = 3000;

class timer {
 public:
  timer() { time_begin = chrono::system_clock::now(); }
  int get() {
    auto time_end = chrono::system_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(time_end - time_begin).count();
  }

 private:
  chrono::system_clock::time_point time_begin;
};

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int n, m, l;

int simulate(vector<string> &a, vector<string> &s) {
  vector<vector<int>> count(m, vector<int>(m));
  for (auto si : s) {
    int y, x, d = 0;
    y = x = m / 2;
    for (auto e : si) {
      string c = {e};
      switch (a[y][x]) {
        case 'D': {
          c = string(2, e);
          break;
        }
        case 'T': {
          c = string(3, e);
          break;
        }
        case 'L': {
          if (e != 'S') c = 'L';
          break;
        }
        case 'R': {
          if (e != 'S') c = 'R';
          break;
        }
      }
      for (auto ci : c) {
        switch (ci) {
          case 'S': {
            int y2 = y + dy[d], x2 = x + dx[d];
            if (a[y2][x2] != '#') {
              y = y2;
              x = x2;
            }
            break;
          }
          case 'L': {
            d = (d + 1) % 4;
            break;
          }
          case 'R': {
            d = (d + 3) % 4;
            break;
          }
        }
      }
    }
    count[y][x]++;
  }
  int score = 0;
  for (auto r : count) {
    for (auto e : r) {
      switch (e) {
        case 1: {
          score += 10;
          break;
        }
        case 2: {
          score += 3;
          break;
        }
        case 3: {
          score += 1;
          break;
        }
      }
    }
  }
  return score;
}

int main() {
  timer t;
  srand(0);

  cin >> n >> m >> l;
  vector<string> s(n);
  for (auto &e : s) {
    cin >> e;
  }
  vector<string> a(m, string(m, '.'));
  for (int i = 0; i < m; i++) {
    a[0][i] = a[m - 1][i] = a[i][0] = a[i][m - 1] = '#';
  }

  int max_score = simulate(s, a);

  while (t.get() < time_limit - 20) {
    int y = 1 + rand() % (m - 2), x = 1 + rand() % (m - 2);
    int prev_tile = a[y][x];
    a[y][x] = "LR"[rand() % 2];
    int score = simulate(a, s);
    if (score > max_score) {
      max_score = score;
    } else {
      a[y][x] = prev_tile;
    }
  }

  for (auto e : a) {
    cout << e << "\r\n" << flush;
  }
  cerr << max_score << endl;
}
