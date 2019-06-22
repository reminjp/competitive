#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int m = (n - 1) * (n - 2) / 2;
  if (m < k) {
    cout << -1 << endl;
    return 0;
  }

  vector<pair<int, int>> v;
  for (int i = 0; i < n - 1; i++) v.push_back({i, n - 1});
  int d = m - k;
  for (int i = 0; d > 0 && i < n - 1; i++) {
    for (int j = i + 1; d > 0 && j < n - 1; j++) {
      v.push_back({i, j});
      d--;
    }
  }

  cout << v.size() << endl;
  for (auto e : v) cout << e.first + 1 << ' ' << e.second + 1 << endl;
}
