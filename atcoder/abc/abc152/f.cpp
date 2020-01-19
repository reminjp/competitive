#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n;
  vector<pair<int, int>> a(n - 1);
  for (auto& e : a) {
    cin >> e.first >> e.second;
    e.first--, e.second--;
  }
  cin >> m;
  vector<pair<int, int>> c(m);
  for (auto& e : c) {
    cin >> e.first >> e.second;
    e.first--, e.second--;
  }

  vector<vector<int>> d(n, vector<int>(n, 1e9)), ij2a(n, vector<int>(n)), next(n, vector<int>(n));
  for (int i = 0; i < n; i++) d[i][i] = 0;
  for (int i = 0; i < n - 1; i++) {
    d[a[i].first][a[i].second] = d[a[i].second][a[i].first] = 1;
    ij2a[a[i].first][a[i].second] = ij2a[a[i].second][a[i].first] = i;
  }
  for (auto& e : next) iota(e.begin(), e.end(), 0);
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (d[i][k] + d[k][j] < d[i][j]) {
          d[i][j] = d[i][k] + d[k][j];
          next[i][j] = next[i][k];
        }
      }
    }
  }

  vector<int> b(n - 1);
  for (int i = 0; i < c.size(); i++) {
    int p = c[i].first;
    while (p != c[i].second) {
      int p2 = next[p][c[i].second];
      b[ij2a[p][p2]] |= 1 << i;
      p = p2;
    }
  }

  vector<vector<ll>> dp(n, vector<ll>(1 << m));
  dp[0][0] = 1;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < (1 << m); j++) {
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j | b[i]] += dp[i][j];
    }
  }
  cout << dp[n - 1][(1 << m) - 1] << endl;
}
