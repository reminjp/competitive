#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, w, h;
  cin >> n >> w >> h;
  vector<pair<int, int>> x, y;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    x.push_back({a - c, a + c});
    y.push_back({b - c, b + c});
  }
  sort(begin(x), end(x));
  sort(begin(y), end(y));
  auto reduce = [](vector<pair<int, int>>& v) {
    for (int i = v.size() - 1; i >= 1; i--) {
      if (v[i].first <= v[i - 1].second) {
        v[i - 1].second = max(v[i - 1].second, v[i].second);
        v.erase(begin(v) + i);
        if (i < v.size()) {
          i++;
        }
      }
    }
  };
  reduce(x);
  reduce(y);
  // for (auto e : x) cerr << e.first << " " << e.second << endl;
  // for (auto e : y) cerr << e.first << " " << e.second << endl;
  bool rx = x.size() == 1 && x.front().first <= 0 && w <= x.front().second;
  bool ry = y.size() == 1 && y.front().first <= 0 && h <= y.front().second;
  cout << (rx || ry ? "Yes" : "No") << endl;
}
