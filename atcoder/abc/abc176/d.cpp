#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9;

int main() {
  int h, w, y1, x1, y2, x2;
  cin >> h >> w >> y1 >> x1 >> y2 >> x2;
  y1--, x1--, y2--, x2--;
  vector<string> s(h);
  for (auto &e : s) cin >> e;

  vector<vector<int>> d(h, vector<int>(w, INF));
  d[y1][x1] = 0;

  priority_queue<tuple<int, int, int>> q;
  q.push({0, y1, x1});
  while (!q.empty()) {
    auto [dyx, y, x] = q.top();
    q.pop();
    if (dyx > d[y][x]) continue;

    for (int dy = -2; dy <= 2; dy++) {
      auto yt = y + dy;
      if ((unsigned)yt >= h) continue;
      for (int dx = -2; dx <= 2; dx++) {
        auto xt = x + dx;
        if ((unsigned)xt >= w) continue;
        if (s[yt][xt] == '#') continue;

        int dt = d[y][x] + (abs(dy) + abs(dx) > 1 ? 1 : 0);
        if (dt < d[yt][xt]) {
          d[yt][xt] = dt;
          q.push({-dt, yt, xt});
        }
      }
    }
  }

  cout << (d[y2][x2] != INF ? d[y2][x2] : -1) << endl;
}
