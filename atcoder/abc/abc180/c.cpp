#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;

  set<ll> r;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i) continue;
    r.insert(i);
    r.insert(n / i);
  }

  for (auto e : r) cout << e << endl;
}
