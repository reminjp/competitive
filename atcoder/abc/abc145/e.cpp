#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, t;
  cin >> n >> t;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(t + 3001)));
  for (int i = 0; i < n; i++) {
    for (int f = 0; f < 2; f++) {
      for (int w = 0; w < t; w++) {
        dp[i + 1][f][w] = max(dp[i + 1][f][w], dp[i][f][w]);
        dp[i + 1][f][w + a[i]] = max(dp[i + 1][f][w + a[i]], dp[i][f][w] + b[i]);
        if (!f) dp[i + 1][1][w] = max(dp[i + 1][1][w], dp[i][0][w] + b[i]);
      }
    }
  }
  cout << *max_element(dp[n][1].begin(), dp[n][1].begin() + t) << endl;
}
