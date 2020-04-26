#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, m, s;
  cin >> n >> m >> s;
  vector<vector<tuple<int, ll, ll>>> g(n);
  for (int i = 0; i < m; i++) {
    ll u, v, a, b;
    cin >> u >> v >> a >> b;
    g[u - 1].push_back({v - 1, a, b});
    g[v - 1].push_back({u - 1, a, b});
  }
  vector<ll> c(n), d(n);
  for (int i = 0; i < n; i++) cin >> c[i] >> d[i];

  ll s_max = 50 * n;
  s = min(s_max, s);

  vector<vector<ll>> r(n, vector<ll>(s_max + 1, 1e18));
  r[0][s] = 0;

  queue<tuple<ll, ll, ll>> q;
  for (int i = 0;; i++) {
    q.push({0, min(s_max, s + i * c[0]), i * d[0]});
    if (s + i * c[i] >= s_max) break;
  }

  while (!q.empty()) {
    auto [i, s1, t1] = q.front();
    q.pop();
    for (auto [j, a, b] : g[i]) {
      for (int k = 0;; k++) {
        ll s2 = min(s_max, s1 + k * c[i] - a);
        ll t2 = t1 + k * d[i] + b;
        if (s2 >= 0 && t2 < r[j][s2]) {
          r[j][s2] = t2;
          q.push({j, s2, t2});
        }
        if (s2 >= s_max) break;
      }
    }
  }

  for (int i = 1; i < n; i++) cout << *min_element(r[i].begin(), r[i].end()) << endl;
}
