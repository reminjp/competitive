#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (auto& e : a) cin >> e;
  for (auto& e : b) cin >> e;

  vector<vector<ll>> dp(n + 2, vector<ll>(m + 2));
  for (int i = 0; i <= n + 1; i++) dp[i][0] = 1;
  for (int j = 0; j <= m + 1; j++) dp[0][j] = 1;
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= m + 1; j++) {
      dp[i][j] += dp[i - 1][j] + dp[i][j - 1] + (mod - dp[i - 1][j - 1]);
      dp[i][j] %= mod;
      if (i - 1 < n && j - 1 < m && a[i - 1] == b[j - 1]) {
        dp[i + 1][j + 1] += dp[i][j];
        dp[i + 1][j + 1] %= mod;
      }
    }
  }
  cout << dp[n + 1][m + 1] << endl;
}
