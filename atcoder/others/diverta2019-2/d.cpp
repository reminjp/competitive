#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll n, ll g1, ll s1, ll b1, ll g2, ll s2, ll b2) {
  vector<ll> dp(n + max({g1, s1, b1}));
  for (ll i = 0; i < n; i++) {
    dp[i + g1] = max(dp[i + g1], dp[i] - g1 + g2);
    dp[i + s1] = max(dp[i + s1], dp[i] - s1 + s2);
    dp[i + b1] = max(dp[i + b1], dp[i] - b1 + b2);
  }
  return n + *max_element(begin(dp), begin(dp) + n + 1);
}

int main() {
  ll n, g1, s1, b1, g2, s2, b2;
  cin >> n >> g1 >> s1 >> b1 >> g2 >> s2 >> b2;
  n = f(n, g1, s1, b1, g2, s2, b2);
  n = f(n, g2, s2, b2, g1, s1, b1);
  cout << n << endl;
}
