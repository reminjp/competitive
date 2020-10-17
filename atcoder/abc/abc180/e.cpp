#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<tuple<int, int, int>> v(n);
  for (auto &[x, y, z] : v) cin >> x >> y >> z;

  vector d(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      d[i][j] += abs(get<0>(v[j]) - get<0>(v[i]));
      d[i][j] += abs(get<1>(v[j]) - get<1>(v[i]));
      d[i][j] += max(0, get<2>(v[j]) - get<2>(v[i]));
    }
  }

  vector dp(1 << n, vector<int>(n, 1e9));
  dp[1][0] = 0;
  for (int b = 0; b < (1 << n); b++) {
    for (int i = 0; i < n; i++) {
      if (!(b >> i & 1)) continue;
      for (int j = 0; j < n; j++) {
        if (b >> j & 1) continue;
        int b2 = b | (1 << j);
        dp[b2][j] = min(dp[b2][j], dp[b][i] + d[i][j]);
      }
    }
  }

  int r = 1e9;
  for (int i = 0; i < n; i++) r = min(r, dp[(1 << n) - 1][i] + d[i][0]);
  cout << r << endl;
}
