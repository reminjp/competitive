#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> l(n);
  for (auto& e : l) cin >> e;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int p, q;
    cin >> p >> q;
    p--, q--;
    g[p].push_back(q);
    g[q].push_back(p);
  }

  vector<ll> s(n), t(n);
  auto dfs1 = [&](auto&& dfs, int i, int j) -> void {
    for (auto e : g[j]) {
      if (e == i) continue;
      dfs(dfs, j, e);
      s[j] += s[e];
      t[j] += t[e];
    }
    s[j] += t[j];
    t[j] += l[j];
  };
  dfs1(dfs1, 0, 0);

  vector<ll> r(n);
  auto dfs2 = [&](auto&& dfs, int i, int j, ll sp, ll tp) -> void {
    r[j] = s[j] + sp + tp;

    ll sc = 0;
    for (auto e : g[j]) {
      if (e == i) continue;
      sc += s[e];
    }
    for (auto e : g[j]) {
      if (e == i) continue;
      dfs(dfs, j, e, sp + tp + (sc - s[e]) + (t[j] - t[e] - l[j]), tp + (t[j] - t[e]));
    }
  };
  dfs2(dfs2, 0, 0, 0, 0);

  for (auto e : r) cout << e << endl;
}
