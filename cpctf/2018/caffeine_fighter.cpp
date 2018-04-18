#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n, m, k, c;
  cin >> n >> m >> k >> c;
  vector<ll> a(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i + 1];
    a[i + 1] += a[i];
  }
  vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
  for (int i = 1; i <= n; i++) {
    dp[i][0] = a[i];
    for (int j = 1; j <= m; j++) {
      dp[i][j] = dp[i - 1][j] + a[i] - a[i - 1];
      if (k < i) {
        dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + a[i - 1] - a[i - k] + c);
      } else {
        dp[i][j] = min(dp[i][j], dp[0][j - 1] + a[i - 1] + c);
      }
    }
  }
  cout << dp[n][m] << endl;
  return 0;
}
