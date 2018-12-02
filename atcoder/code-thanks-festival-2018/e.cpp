#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = (int)1e9 + 7;

int main() {
  int t;
  cin >> t;
  vector<int> a(t);
  int a_max = 0;
  for (auto &e : a) {
    cin >> e;
    a_max = max(a_max, e);
  }
  vector<vector<ll>> dp(t + 1, vector<ll>(2 * a_max + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= t; i++) {
    for (int j = 0; j <= a[i - 1]; j++) {
      for (int k = 0; k <= 2 * a_max; k += 2) {
        dp[i][j + k / 2] += dp[i - 1][k];
        dp[i][j + k / 2] %= mod;
      }
    }
  }

  ll r = 0;
  for (int i = 1; i < t; i++) {
    r += dp[i][1];
    r %= mod;
  }
  for (int i = 1; i <= 2 * a_max; i *= 2) {
    r += dp[t][i];
    r %= mod;
  }
  cout << r << endl;
}
