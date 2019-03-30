#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 1e9 + 7;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> s(n);
  for (auto &e : s) {
    cin >> e;
  }
  sort(begin(s), end(s));

  vector<int> ub(x + 1);
  for (int i = 0; i <= x; i++) {
    ub[i] = upper_bound(begin(s), end(s), i) - begin(s);
  }

  vector<vector<ll>> dp(n + 1, vector<ll>(x + 1));
  dp[0][x] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= x; j++) {
      if (!dp[i][j]) continue;
      int b = ub[j];
      for (int k = 0; k < b; k++) {
        int t = j % s[k];
        dp[i + 1][t] += dp[i][j];
        dp[i + 1][t] %= mod;
      }
      dp[i + 1][j] += (n - b - i) * dp[i][j];
      dp[i + 1][j] %= mod;
    }
  }

  ll r = 0;
  for (int j = 1; j <= x; j++) {
    r += j * dp[n][j];
    r %= mod;
  }
  cout << r << endl;
}
