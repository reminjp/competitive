#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> a(m);
  vector<vector<int>> d(n, vector<int>(n, 1e9));
  for (auto& e : a) {
    cin >> get<0>(e) >> get<1>(e) >> get<2>(e);
    d[get<0>(e) - 1][get<1>(e) - 1] = get<2>(e);
    d[get<1>(e) - 1][get<0>(e) - 1] = get<2>(e);
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  bool is_possible = true;
  for (auto e : a) {
    is_possible = is_possible && d[get<0>(e) - 1][get<1>(e) - 1] == get<2>(e);
  }
  if (is_possible) {
    cout << a.size() << endl;
    for (auto e : a) cout << get<0>(e) << ' ' << get<1>(e) << ' ' << get<2>(e) << endl;
  } else {
    cout << "Impossible" << endl;
  }
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
