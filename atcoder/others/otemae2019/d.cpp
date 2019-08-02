#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> s(m);
  for (auto& e : s) cin >> e;

  vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(m + 2, vector<ll>(3)));
  dp[0][0][0] = 1;
  for (int j = 0; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      for (int k = 0; k < 3; k++) {
        for (int d = i == 1; d < 10; d++) {
          bool b3 = (k + d) % 3 == 0, b5 = d == 0 || d == 5;
          if (j && ((s[j - 1] == "Fizz" && b3 && !b5) || (s[j - 1] == "Buzz" && !b3 && b5) ||
                    (s[j - 1] == "FizzBuzz" && b3 && b5))) {
            (dp[i][j][(k + d) % 3] += dp[i - 1][j - 1][k]) %= mod;
          } else if (!b3 && !b5) {
            (dp[i][j][(k + d) % 3] += dp[i - 1][j][k]) %= mod;
          }
        }
      }
    }
  }
  cout << accumulate(begin(dp[n][m]), end(dp[n][m]), 0ll) % mod << endl;
}
