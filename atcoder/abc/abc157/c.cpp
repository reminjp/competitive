#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> v(m);
  for (auto& e : v) cin >> e.first >> e.second;

  for (int d = 0; d < 1000; d++) {
    auto s = to_string(d);
    if (s.size() != n) continue;
    bool b = true;
    for (auto e : v) b = b && (s[e.first - 1] - '0') == e.second;
    if (b) {
      cout << d << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
