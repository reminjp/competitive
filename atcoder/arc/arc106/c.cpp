#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  if (m != 0 && (m < 0 || n - 2 < m)) {
    cout << -1 << endl;
    return 0;
  }

  vector<pair<int, int>> r(n);
  for (int i = 0; i < n; i++) {
    r[i] = {10 * i + 2, 10 * i + 3};
  }
  if (m > 0) r[n - 1] = {1, 10 * m + 4};

  for (auto e : r) cout << e.first << ' ' << e.second << endl;
}
