#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> m(n, vector<int>(n));
  for (auto& mi : m)
    for (auto& e : mi) cin >> e;

  int k = 0, r = 0, c = 0;
  for (int i = 0; i < n; i++) {
    k += m[i][i];
    set<int> sr, sc;
    for (int j = 0; j < n; j++) {
      sr.insert(m[i][j]);
      sc.insert(m[j][i]);
    }
    if (sr.size() != n) r++;
    if (sc.size() != n) c++;
  }
  cout << k << ' ' << r << ' ' << c << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
