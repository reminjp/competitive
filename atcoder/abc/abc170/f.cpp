#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
  int h, w, k, x1, y1, x2, y2;
  cin >> h >> w >> k >> y1 >> x1 >> y2 >> x2;
  x1--, y1--, x2--, y2--;
  vector<string> c(h);
  for (auto& e : c) cin >> e;

  struct state {
    int y, x, d, k, cost;
  };
  auto compare = [](state a, state b) { return a.cost > b.cost; };

  vector<vector<vector<state>>> r(h, vector<vector<state>>(w, vector<state>(4, {0, 0, -1, 0, INF})));
  r[y1][x1][0] = {y1, x1, -1, 0, 0};
  priority_queue<state, vector<state>, decltype(compare)> q(compare);
  q.push(r[y1][x1][0]);
  while (!q.empty()) {
    auto e = q.top();
    q.pop();
    for (int i = 0; i < 4; i++) {
      auto e2 = e;
      e2.y += dy[i];
      e2.x += dx[i];
      if (unsigned(e2.y) >= h || unsigned(e2.x) >= w) continue;
      if (c[e2.y][e2.x] == '@') continue;

      if (e.d == i && e.k < k) {
        e2.k++;
      } else {
        e2.d = i;
        e2.k = 1;
        e2.cost++;
      }

      if (e2.cost < r[e2.y][e2.x][e2.d].cost || (e2.cost == r[e2.y][e2.x][e2.d].cost && e2.k < r[e2.y][e2.x][e2.d].k)) {
        r[e2.y][e2.x][e2.d] = e2;
        q.push(e2);
      }
    }
  }
  int rmin = INF;
  for (int i = 0; i < 4; i++) rmin = min(rmin, r[y2][x2][i].cost);
  cout << (rmin == INF ? -1 : rmin) << endl;
}
