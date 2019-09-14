#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1e18;

int main() {
  int n, m;
  cin >> n;
  vector<ll> a(n), b(n);
  for (auto &e : a) cin >> e;
  for (auto &e : b) cin >> e;
  cin >> m;
  vector<ll> q(m);
  for (auto &e : q) cin >> e;

  vector<pair<ll, ll>> v;
  for (int i = 0; i + 1 < n; i++) a[i + 1] += a[i];
  for (int i = 0; i < n; i++) v.push_back({a[i], b[i]});
  for (auto e : q) v.push_back({e, INF});
  sort(begin(v), end(v));
  ll t = 0, x = 0;
  for (auto e : v) {
    x -= e.first - t;
    t = e.first;
    if (e.second != INF) {
      x += e.second;
    } else {
      cout << (x < 0 ? "kame" : x > 0 ? "usagi" : "draw") << endl;
    }
  }
}
