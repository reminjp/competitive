#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;

int main() {
  int n;
  cin >> n;
  ll zero = 0;
  map<pair<ll, ll>, ll> m;
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    if (a == 0 && b == 0) {
      zero++;
    } else {
      auto d = gcd(a, b);
      a /= d;
      b /= d;
      m[{a, b}]++;
    }
  }

  vector<ll> p(n + 1);
  p[0] = 1;
  for (int i = 1; i <= n; i++) p[i] = p[i - 1] * 2 % MOD;

  ll r = 1;
  for (auto& e : m) {
    auto [a, b] = e.first;
    ll c1 = e.second, c2 = 0;
    if (c1 == 0) continue;
    e.second = 0;
    if (m.count({-a, -b})) {
      c1 += m[{-a, -b}];
      m[{-a, -b}] = 0;
    }
    if (m.count({b, -a})) {
      c2 += m[{b, -a}];
      m[{b, -a}] = 0;
    }
    if (m.count({-b, a})) {
      c2 += m[{-b, a}];
      m[{-b, a}] = 0;
    }
    r *= (1 + (p[c1] - 1) + (p[c2] - 1)) % MOD;
    r %= MOD;
  }
  r -= 1;
  r += zero;
  r %= MOD;
  cout << r << endl;
}
