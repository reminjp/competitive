#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  while (n--) {
    int x, y;
    cin >> x >> y;
    v.push_back({x, -100});
    v.push_back({x, 100});
    v.push_back({x, y});
  }

  dsu d(v.size());
  for (int i = 2; i < v.size(); i++) {
    if (v[i].second == -100) d.merge(0, i);
    if (v[i].second == 100) d.merge(1, i);
  }

  set<tuple<double, int, int>> q;
  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) q.insert({hypot(v[i].first - v[j].first, v[i].second - v[j].second), i, j});
  }

  double r = 1e9;
  for (auto [h, i, j] : q) {
    if (d.same(0, i) && d.same(1, j) || d.same(1, i) && d.same(0, j)) {
      r = h / 2;
      break;
    }
    d.merge(i, j);
  }
  cout << fixed << setprecision(5) << r << endl;
}
