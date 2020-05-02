#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T>
void set_if_less(T& a, T b) {
  if (a > b) a = b;
}

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<ll> c(n), d(n);
  for (auto& e : c) cin >> e;
  for (auto& e : d) cin >> e;

  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 1e18));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // ''
      set_if_less(dp[i + 1][j], dp[i][j] + d[i]);
      // '('
      set_if_less(dp[i + 1][j + 1], dp[i][j] + (s[i] == '(' ? 0 : c[i]));
      // ')'
      if (j - 1 >= 0) set_if_less(dp[i + 1][j - 1], dp[i][j] + (s[i] == ')' ? 0 : c[i]));
    }
  }
  cout << dp[n][0] << endl;
}
