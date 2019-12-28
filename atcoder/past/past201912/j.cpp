#include <bits/stdc++.h>
using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  for (auto& v : a) {
    for (auto& e : v) cin >> e;
  }

  int r = 1e9;
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      vector<vector<int>> c(h, vector<int>(w, 1e9));
      c[y][x] = a[y][x];
      queue<pair<int, int>> q;
      q.push({y, x});
      while (!q.empty()) {
        auto e = q.front();
        q.pop();
        int y1 = e.first, x1 = e.second;
        for (int i = 0; i < 4; i++) {
          int y2 = y1 + dy[i], x2 = x1 + dx[i];
          if (0 <= y2 && y2 < h && 0 <= x2 && x2 < w && c[y1][x1] + a[y2][x2] < c[y2][x2]) {
            c[y2][x2] = c[y1][x1] + a[y2][x2];
            q.push({y2, x2});
          }
        }
      }
      r = min(r, c[0][w - 1] + c[h - 1][0] + c[h - 1][w - 1] - 2 * a[y][x]);
    }
  }
  cout << r << endl;
}
