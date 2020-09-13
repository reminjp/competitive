#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 1e9 + 7;
constexpr int M = 3;

int main() {
  int n;
  cin >> n;

  vector<ll> dp(n + 1);
  dp[0] = 1;
  for (int i = 0; i <= n - M; i++) {
    for (int j = M; j <= n; j++) (dp[i + j] += dp[i]) %= MOD;
  }
  cout << dp[n] << endl;
}
