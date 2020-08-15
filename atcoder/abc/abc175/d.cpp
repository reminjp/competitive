#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  vector<ll> c(n);
  for (auto& e : p) {
    cin >> e;
    e--;
  }
  for (auto& e : c) cin >> e;

  vector<ll> s1(n), s2(n), d1(n), d2(n);
  for (int i = 0; i < n; i++) {
    if (d1[i]) continue;
    d1[i] = 1;
    for (int j = i; !d2[p[j]]; j = p[j]) {
      if (!d1[p[j]]) {
        s1[p[j]] = s1[j] + c[p[j]];
        d1[p[j]] = d1[j] + 1;
      } else {
        s2[p[j]] = (d2[j] ? s2[j] : s1[j]) + c[p[j]];
        d2[p[j]] = (d2[j] ? d2[j] : d1[j]) + 1;
      }
    }
  }

  ll r = -1e18;
  for (int i = 0; i < n; i++) {
    ll ri = 0;
    for (int j = i, ki = k; ki;) {
      if (d2[j] && 2 * (d2[j] - d1[j]) <= ki) {
        ll t = ki / (d2[j] - d1[j]) - 1;
        ri += t * (s2[j] - s1[j]);
        ki -= t * (d2[j] - d1[j]);
      } else {
        ri += c[p[j]];
        ki--;
        j = p[j];
      }
      r = max(r, ri);
      ri = max(ri, 0ll);
    }
  }
  cout << r << endl;
}
