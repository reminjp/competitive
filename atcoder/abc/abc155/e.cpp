#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  int n = s.size();

  vector<vector<int>> dp(n + 1, vector<int>(2, 1e9));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    int d = s[i] - '0';
    for (int j = 0; j < 2; j++) {
      dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + d + j);
      dp[i + 1][1] = min(dp[i + 1][1], dp[i][j] + (10 - d - j));
    }
  }
  cout << min(dp[n][0], dp[n][1] + 1) << endl;
}
