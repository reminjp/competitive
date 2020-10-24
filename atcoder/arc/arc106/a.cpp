#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;

  map<ll, ll> m;
  for (ll i = 1, p = 5; p <= n; i++, p *= 5) m[p] = i;

  for (ll i = 1, p = 3; p <= n; i++, p *= 3) {
    if (m.count(n - p)) {
      cout << i << ' ' << m[n - p] << endl;
      return 0;
    }
  }

  cout << -1 << endl;
}
