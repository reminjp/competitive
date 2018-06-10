#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  set<int> s;
  for (int i = 1; i <= n; i *= 6) {
    s.insert(i);
  }
  for (int i = 1; i <= n; i *= 9) {
    s.insert(i);
  }
  vector<int> dp(n + 1, n);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (auto e : s) {
      if (i - e >= 0) {
        dp[i] = min(dp[i], dp[i - e] + 1);
      }
    }
  }
  cout << dp[n] << endl;
  return 0;
}
