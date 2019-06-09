#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 1e9 + 7;

int main() {
  string l;
  cin >> l;
  vector<vector<ll>> dp(l.size() + 1, vector<ll>(2));
  dp[0][0] = 1;
  for (int i = 0; i < l.size(); i++) {
    if (l[i] == '1') {
      dp[i + 1][0] += 2 * dp[i][0] % mod;
      dp[i + 1][0] %= mod;
      dp[i + 1][1] += dp[i][0];
      dp[i + 1][1] += 3 * dp[i][1] % mod;
      dp[i + 1][1] %= mod;
    } else {
      dp[i + 1][0] += dp[i][0];
      dp[i + 1][0] %= mod;
      dp[i + 1][1] += 3 * dp[i][1] % mod;
      dp[i + 1][1] %= mod;
    }
  }
  cout << (dp[l.size()][0] + dp[l.size()][1]) % mod << endl;
}
