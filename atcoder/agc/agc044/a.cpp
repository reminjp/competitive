#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    map<ll, ll> m;
    auto f = [&](auto&& f, ll x) -> ll {
      if (x == 0) return 0;
      if (x == 1) return d;
      if (x == 2) return min(2 * d, d + a);
      if (m.count(x)) return m[x];
      ll r = 1e18;
      if (x <= 1e18 / d) r = x * d;
      r = min(r, f(f, x / 2) + a + abs(x / 2 * 2 - x) * d);
      r = min(r, f(f, x / 2 + 1) + a + abs((x / 2 + 1) * 2 - x) * d);
      r = min(r, f(f, x / 3) + b + abs(x / 3 * 3 - x) * d);
      r = min(r, f(f, x / 3 + 1) + b + abs((x / 3 + 1) * 3 - x) * d);
      r = min(r, f(f, x / 5) + c + abs(x / 5 * 5 - x) * d);
      r = min(r, f(f, x / 5 + 1) + c + abs((x / 5 + 1) * 5 - x) * d);
      return m[x] = r;
    };
    cout << f(f, n) << endl;
  }
}
