#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 998244353;

int main() {
  int n;
  string x;
  cin >> n >> x;

  vector<int> c;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0 && n / i % 2 == 1) c.push_back(i);
  }

  vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(2, vector<ll>(c.size())));
  fill(dp[0][0].begin(), dp[0][0].end(), 1);
  for (int i = 0; i < n; i++) {
    for (int less = 0; less < 2; less++) {
      for (int j = 0; j < c.size(); j++) {
        if (i < c[j]) {
          (dp[i + 1][less][j] += dp[i][less][j]) %= MOD;
          if (less || x[i] - '0' == 1) (dp[i + 1][true][j] += dp[i][less][j]) %= MOD;
        } else if (x[i - c[j]] - '0' != x[i] - '0') {
          (dp[i + 1][less][j] += dp[i][less][j]) %= MOD;
        } else if (less || x[i] - '0' == 1) {
          (dp[i + 1][true][j] += dp[i][less][j]) %= MOD;
        }
      }
    }
  }
  for (int less = 0; less < 2; less++) {
    for (int j = 0; j < c.size(); j++) {
      for (int k = j + 1; k < c.size(); k++) {
        if (c[k] % c[j] == 0 && c[k] / c[j] % 2 == 1) dp[n][less][k] = (MOD + dp[n][less][k] - dp[n][less][j]) % MOD;
      }
    }
  }

  // for (auto e : c) cerr << e << ' ';
  // cerr << endl;
  // for (int i = 0; i < n; i++) {
  //   cerr << i + 1 << endl;
  //   for (int less = 0; less < 2; less++) {
  //     for (int j = 0; j < c.size(); j++) {
  //       cerr << less << ' ' << c[j] << ' ' << dp[i + 1][less][j] << endl;
  //     }
  //   }
  // }

  ll r = 0;
  for (int less = 0; less < 2; less++) {
    for (int j = 0; j < c.size(); j++) {
      r += dp[n][less][j] * (2 * c[j] % MOD) % MOD;
      r %= MOD;
    }
  }
  cout << r << endl;
}
