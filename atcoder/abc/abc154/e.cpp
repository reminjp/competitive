#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();

  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 2, vector<int>(2)));
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k + 1; j++) {
      if (s[i] - '0' == 0) {
        dp[i + 1][j][0] += dp[i][j][0];
      } else {
        dp[i + 1][j][1] += dp[i][j][0];
        dp[i + 1][j + 1][1] += (s[i] - '0' - 1) * dp[i][j][0];
        dp[i + 1][j + 1][0] += dp[i][j][0];
      }
      dp[i + 1][j][1] += dp[i][j][1];
      dp[i + 1][j + 1][1] += 9 * dp[i][j][1];
    }
  }
  cout << dp[n][k][0] + dp[n][k][1] << endl;
}
