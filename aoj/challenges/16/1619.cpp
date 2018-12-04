#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m, n) {
    vector<bitset<500>> b(n);
    for (auto& e : b) {
      cin >> e;
    }

    int r = 0;
    if (n <= 23) {
      for (int i = 0; i < (1 << n); i++) {
        bitset<23> t(i);
        bitset<500> s;
        for (int j = 0; j < n; j++) {
          if (t.test(j)) s ^= b[j];
        }
        if (s.none()) {
          r = max(r, (int)t.count());
        }
      }
    } else {
      vector<vector<int>> dp(n + 1, vector<int>(1 << m, -1e9));
      dp[0][0] = 0;
      for (int i = 0; i < n; i++) {
        int t = b[i].to_ulong();
        for (int j = 0; j < (1 << m); j++) {
          dp[i + 1][j] = max(dp[i][j], dp[i][j ^ t] + 1);
        }
      }
      r = dp[n][0];
    }
    cout << r << endl;
  }
}
