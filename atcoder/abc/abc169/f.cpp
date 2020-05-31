#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;

int main() {
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  vector<vector<ll>> dp(n + 1, vector<ll>(s + 3001));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= s; j++) {
      (dp[i + 1][j] += 2 * dp[i][j] % MOD) %= MOD;
      (dp[i + 1][j + a[i]] += dp[i][j]) %= MOD;
    }
  }
  cout << dp[n][s] << endl;
}
