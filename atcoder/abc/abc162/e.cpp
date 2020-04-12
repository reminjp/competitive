#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 1e9 + 7;

int main() {
  ll n, k;
  cin >> n >> k;

  vector<vector<ll>> d(k + 1);
  for (ll i = 1; i <= k; i++) {
    for (ll j = 1; j * j <= i; j++) {
      if (i % j == 0) {
        if (j != i) d[i].push_back(j);
        if (j != 1 && j * j != i) d[i].push_back(i / j);
      }
    }
  }

  vector<ll> p(k + 1), t(k + 1);
  for (ll i = k; i >= 1; i--) {
    ll x = k / i;
    if (!p[x]) {
      // pow(x, n)
      p[x] = 1;
      for (ll j = 0; j < n; j++) (p[x] *= x) %= MOD;
    }
    t[i] += p[x];
    t[i] %= MOD;
    for (auto e : d[i]) {
      t[e] += MOD - t[i];
      t[e] %= MOD;
    }
  }

  ll r = 0;
  for (ll i = 1; i <= k; i++) {
    r += i * t[i];
    r %= MOD;
  }
  cout << r << endl;
}
