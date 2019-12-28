#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, ll>> a(m);
  for (auto& e : a) {
    string s;
    cin >> s >> e.second;
    for (int i = 0; i < n; i++) e.first |= (s[i] == 'Y') << i;
  }

  vector<vector<ll>> dp(m + 1, vector<ll>(1 << n, 1e18));
  dp[0][0] = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < (1 << n); j++) {
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      dp[i + 1][j | a[i].first] = min(dp[i + 1][j | a[i].first], dp[i][j] + a[i].second);
    }
  }
  cout << (dp[m][(1 << n) - 1] == 1e18 ? -1 : dp[m][(1 << n) - 1]) << endl;
}
