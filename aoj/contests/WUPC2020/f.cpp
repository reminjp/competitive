#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;

  ll r = 0;
  for (ll i = 1; i <= n; i *= 2) {
    ll x1 = 0, x2 = n / i * i;
    ll t = x2;
    while ((x1 + x2) % 2 == 0) {
      auto x3 = (x1 + x2) / 2;
      t += x3;
      x1 = x2;
      x2 = x3;
    }
    r = max(r, t);
  }
  cout << r << endl;
}
