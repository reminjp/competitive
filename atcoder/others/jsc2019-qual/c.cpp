#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 1e9 + 7;

int main() {
  int n;
  string s;
  cin >> n >> s;

  vector<ll> f(n + 1);
  f[0] = 1;
  for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i % mod;

  vector<map<int, ll>> dp(2 * n + 1);
  dp[0][0] = 1;
  for (int i = 0; i < 2 * n; i++) {
    for (auto e : dp[i]) {
      if ((e.first + int(s[i] == 'W')) % 2 == 0) {
        if (e.first + 1 <= n) (dp[i + 1][e.first + 1] += e.second) %= mod;
      } else {
        if (e.first - 1 >= 0) (dp[i + 1][e.first - 1] += e.second * e.first % mod) %= mod;
      }
    }
  }
  cout << dp[2 * n][0] * f[n] % mod << endl;
}
