#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <atcoder/all>
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(n);
  for (auto &e : a) cin >> e;
  for (auto &e : b) cin >> e;

  dsu d(n);
  while (m--) {
    int p, q;
    cin >> p >> q;
    d.merge(p - 1, q - 1);
  }

  bool r = true;
  for (const auto &group : d.groups()) {
    ll as = 0, bs = 0;
    for (auto e : group) {
      as += a[e];
      bs += b[e];
    }
    r = r && as == bs;
  }
  cout << (r ? "Yes" : "No") << endl;
}
