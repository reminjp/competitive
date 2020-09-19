#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 998244353;

int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> s(k);
  for (auto &e : s) {
    cin >> e.first >> e.second;
    e.second++;
  }

  vector<ll> dp(n + 2), d(2 * n + 2);
  d[1] = 1, d[2] = -1;
  for (int i = 1; i <= n; i++) {
    (dp[i] = dp[i - 1] + d[i]) %= MOD;
    for (auto e : s) {
      (d[i + e.first] += dp[i]) %= MOD;
      (d[i + e.second] += MOD - dp[i]) %= MOD;
    }
  }
  cout << dp[n] << endl;
}
