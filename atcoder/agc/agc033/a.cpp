#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  for (auto& e : a) cin >> e;

  vector<vector<int>> d(h, vector<int>(w, 1e9));
  queue<pair<int, int>> q;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] == '#') {
        q.push({i, j});
        d[i][j] = 0;
      }
    }
  }
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int y = p.first + dy[i], x = p.second + dx[i];
      if (!(0 <= y && y < h && 0 <= x && x < w)) continue;
      if (d[p.first][p.second] + 1 >= d[y][x]) continue;
      d[y][x] = d[p.first][p.second] + 1;
      q.push({y, x});
    }
  }

  int r = 0;
  for (const auto& row : d) {
    for (auto e : row) {
      r = max(r, e);
    }
  }
  cout << r << endl;
}
