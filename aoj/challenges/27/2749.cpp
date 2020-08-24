// 2020-08-24
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  for (int n, m; cin >> n >> m, n;) {
    vector<int> s(n), d(m);
    for (auto &e : s) cin >> e;
    for (auto &e : d) cin >> e;
    sort(d.begin(), d.end());

    vector<int> sum(1 << n);
    for (int j = 0; j < 1 << n; j++) {
      for (int k = 0; k < n; k++) {
        if (j & 1 << k) sum[j] += s[k];
      }
    }

    vector<int> dp(1 << n);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < 1 << n; j++) {
        dp[j] += abs(sum[j] - d[i]);
      }
      for (int j = 0; j < 1 << n; j++) {
        for (int k = 0; k < n; k++) {
          dp[j] = min(dp[j], dp[j & ~(1 << k)]);
        }
      }
    }
    cout << dp[(1 << n) - 1] << endl;
  }
}
