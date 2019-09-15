#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  int r = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s[i - 1] == s[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
      r = max(r, min(abs(i - j), dp[i][j]));
    }
  }
  cout << r << endl;
}
