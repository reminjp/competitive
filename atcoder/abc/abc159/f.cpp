#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 998244353;

int main() {
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  ll r = 0;
  vector<vector<ll>> dp(n + 1, vector<ll>(2 * 3000 + 1));
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < s; k++) {
      (dp[i + 1][k] += dp[i][k]) %= MOD;
      (dp[i + 1][k + a[i]] += dp[i][k]) %= MOD;
    }
    (dp[i + 1][a[i]] += i + 1) %= MOD;

    r += dp[i + 1][s] * (n - i) % MOD;
    r %= MOD;
  }
  cout << r << endl;
}
