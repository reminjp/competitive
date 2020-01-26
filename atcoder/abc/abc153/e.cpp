#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, n;
  cin >> h >> n;
  vector<pair<int, int>> a(n);
  for (auto& e : a) cin >> e.first >> e.second;

  vector<int> dp(h + 1, 1e9);
  dp[h] = 0;
  for (auto e : a) {
    for (int i = h; i > 0; i--) {
      dp[max(0, i - e.first)] = min(dp[max(0, i - e.first)], dp[i] + e.second);
    }
  }
  cout << dp[0] << endl;
}
