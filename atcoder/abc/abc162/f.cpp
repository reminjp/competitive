#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& e : a) cin >> e;

  int m = 1 + n % 2;
  vector<vector<ll>> dp(n + 2, vector<ll>(m + 1, -1e18));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m; j++) {
      dp[i + 2][j] = max(dp[i + 2][j], dp[i][j] + a[i]);
      if (j + 1 <= m) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
    }
  }
  cout << max(*max_element(dp[n].begin(), dp[n].end()), *max_element(dp[n + 1].begin(), dp[n + 1].end())) << endl;
}
