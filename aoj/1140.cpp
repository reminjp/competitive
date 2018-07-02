#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
  int w, h;
  while (cin >> w >> h, w) {
    vector<string> c(h);
    for (auto &e : c) {
      cin >> e;
    }
    vector<pair<int, int>> p;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (c[i][j] == '*') {
          p.push_back({i, j});
        } else if (c[i][j] == 'o') {
          p.insert(begin(p), {i, j});
        }
      }
    }

    vector<vector<int>> v(p.size(), vector<int>(p.size(), 1e9));
    for (int i = 0; i < p.size(); i++) {
      vector<vector<int>> bfs(h, vector<int>(w, 1e9));
      bfs[p[i].first][p[i].second] = 0;
      queue<pair<int, int>> q;
      q.push(p[i]);
      while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int j = 0; j < 4; j++) {
          int y = t.first + dy[j], x = t.second + dx[j];
          if (0 <= y && y < h && 0 <= x && x < w && c[y][x] != 'x' && bfs[y][x] == (int)1e9) {
            bfs[y][x] = bfs[t.first][t.second] + 1;
            q.push({y, x});
          }
        }
      }
      for (int j = 0; j < p.size(); j++) {
        v[i][j] = bfs[p[j].first][p[j].second];
      }
    }

    vector<vector<int>> dp(1 << p.size(), vector<int>(p.size(), 1e9));
    dp[1 << 0][0] = 0;
    for (int i = 0; i < 1 << p.size(); i++) {
      for (int j = 0; j < p.size(); j++) {
        if (!(i & (1 << j))) {
          for (int k = 0; k < p.size(); k++) {
            dp[i | (1 << j)][j] = min(dp[i | (1 << j)][j], dp[i][k] + v[k][j]);
          }
        }
      }
    }

    int m = 1e9;
    for (int i = 0; i < p.size(); i++) {
      m = min(m, dp[(1 << p.size()) - 1][i]);
    }
    cout << (m == (int)1e9 ? -1 : m) << endl;
  }
}
