#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<vector<vector<vector<ll>>>> dp(n + 1, vector<vector<vector<ll>>>(4, vector<vector<ll>>(4, vector<ll>(4))));
  dp[0][3][3][3] = 1;
  for (int i = 0; i < n; i++) {
    for (int c1 = 0; c1 < 4; c1++) {
      for (int c2 = 0; c2 < 4; c2++) {
        for (int c3 = 0; c3 < 4; c3++) {
          vector<bool> b(4, true);
          if (c1 == 0 && c2 == 2) b[1] = false;
          if (c1 == 0 && c3 == 2) b[1] = false;
          if (c2 == 0 && c3 == 2) b[1] = false;
          if (c2 == 2 && c3 == 0) b[1] = false;
          if (c2 == 0 && c3 == 1) b[2] = false;
          for (int j = 0; j < 4; j++) {
            if (!b[j]) continue;
            dp[i + 1][c2][c3][j] += dp[i][c1][c2][c3];
            dp[i + 1][c2][c3][j] %= mod;
          }
        }
      }
    }
  }
  ll r = 0;
  for (int c1 = 0; c1 < 4; c1++) {
    for (int c2 = 0; c2 < 4; c2++) {
      for (int c3 = 0; c3 < 4; c3++) {
        r += dp[n][c1][c2][c3];
        r %= mod;
      }
    }
  }
  cout << r << endl;
}
