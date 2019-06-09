#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;
  vector<bool> a(n + 1);
  for (int i = 0; i < m; i++) {
    int e;
    cin >> e;
    a[e] = true;
  }
  vector<int> dp(n + 2);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    if (a[i]) dp[i] = 0;
    for (int j = 1; j <= 2; j++) {
      dp[i + j] += dp[i];
      dp[i + j] %= mod;
    }
  }
  cout << dp[n] << endl;
}
