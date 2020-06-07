#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9;
constexpr int M = 201;

int dx[] = {1, 0, -1, 1, -1, 0};
int dy[] = {1, 1, 1, 0, 0, -1};

int main() {
  int n, gx, gy;
  cin >> n >> gx >> gy;
  gx += M;
  gy += M;
  vector<vector<bool>> m(2 * M + 1, vector<bool>(2 * M + 1));
  while (n--) {
    int x, y;
    cin >> x >> y;
    x += M;
    y += M;
    m[x][y] = true;
  }

  vector<vector<int>> d(2 * M + 1, vector<int>(2 * M + 1, INF));
  d[M][M] = 0;
  queue<pair<int, int>> q;
  q.push({M, M});
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int i = 0; i < 6; i++) {
      int x2 = x + dx[i], y2 = y + dy[i];
      if (unsigned(x2) >= 2 * M + 1 || unsigned(y2) >= 2 * M + 1) continue;
      if (m[x2][y2]) continue;
      if (d[x2][y2] <= d[x][y] + 1) continue;
      d[x2][y2] = d[x][y] + 1;
      q.push({x2, y2});
    }
  }

  cout << (d[gx][gy] == INF ? -1 : d[gx][gy]) << endl;
}
