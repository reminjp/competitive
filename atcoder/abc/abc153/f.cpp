#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, d, a;
  cin >> n >> d >> a;
  vector<pair<ll, ll>> v(n);
  for (auto& e : v) cin >> e.first >> e.second;
  sort(v.begin(), v.end());
  vector<ll> x(n), h(n);
  for (int i = 0; i < n; i++) x[i] = v[i].first, h[i] = (v[i].second - 1) / a + 1;

  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    w[i] = upper_bound(x.begin(), x.end(), x[i] + 2 * d) - x.begin();
  }

  ll m = 0, s = 0;
  vector<ll> t(n + 1);
  for (int i = 0; i < n; i++) {
    s += t[i];
    if (s < h[i]) {
      m += h[i] - s;
      t[i] += h[i] - s;
      t[w[i]] -= h[i] - s;
      s = h[i];
    }
  }
  cout << m << endl;
}
