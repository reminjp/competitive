#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto& e : a) cin >> e.first >> e.second;

  bool r = false;
  for (auto [x1, y1] : a) {
    for (auto [x2, y2] : a) {
      if (x1 == x2 && y1 == y2) continue;
      for (auto [x3, y3] : a) {
        if (x1 == x3 && y1 == y3) continue;
        if (x2 == x3 && y2 == y3) continue;
        auto dx1 = x1 - x3, dy1 = y1 - y3;
        auto dx2 = x2 - x3, dy2 = y2 - y3;
        r = r || dx1 * dy2 == dx2 * dy1;
      }
    }
  }
  cout << (r ? "Yes" : "No") << endl;
}
