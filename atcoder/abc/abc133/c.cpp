#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 2019;

int main() {
  ll l, r;
  cin >> l >> r;
  ll m;
  if (l + mod <= r) {
    m = 0;
  } else {
    m = 4e18;
    for (ll i = l; i <= r; i++) {
      for (ll j = i + 1; j <= r; j++) {
        m = min(m, i * j % mod);
      }
    }
  }
  cout << m << endl;
}
