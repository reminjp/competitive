#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m), k(m);
  for (int i = 0; i < m; i++) {
    int b;
    cin >> a[i] >> b;
    for (; b > 0; b--) {
      int c;
      cin >> c;
      k[i] |= 1 << c - 1;
    }
  }
  vector<vector<int>> dp(m + 1, vector<int>(1 << n, 1e9));
  dp[0][0] = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < (1 << n); j++) {
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      dp[i + 1][j | k[i]] = min(dp[i + 1][j | k[i]], dp[i][j] + a[i]);
    }
  }
  cout << (dp[m][(1 << n) - 1] != int(1e9) ? dp[m][(1 << n) - 1] : -1) << endl;
}
