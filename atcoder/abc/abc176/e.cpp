#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, n;
  cin >> h >> w >> n;

  vector<pair<int, int>> vy(h), vx(w);
  for (int i = 0; i < h; i++) vy[i].second = i;
  for (int i = 0; i < w; i++) vx[i].second = i;

  set<pair<int, int>> s;
  for (int i = 0; i < n; i++) {
    int y, x;
    cin >> y >> x;
    y--, x--;
    vy[y].first++;
    vx[x].first++;
    s.insert({y, x});
  }

  sort(vy.rbegin(), vy.rend());
  sort(vx.rbegin(), vx.rend());

  int r = min(2, n);
  for (auto ey : vy) {
    if (ey.first + vx.front().first <= r) break;
    for (auto ex : vx) {
      if (ey.first + ex.first <= r) break;
      r = max(r, ey.first + ex.first - (int)s.count({ey.second, ex.second}));
    }
  }
  cout << r << endl;
}
