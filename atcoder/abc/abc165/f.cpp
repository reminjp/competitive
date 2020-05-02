#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9 + 1;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &e : a) cin >> e;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> r(n), t(n, INF);
  auto dfs = [&](auto &&dfs, int i, int j) -> void {
    auto it = lower_bound(t.begin(), t.end(), a[j]);
    auto p = *it;
    *it = a[j];
    r[j] = lower_bound(t.begin(), t.end(), INF) - t.begin();

    for (auto e : g[j]) {
      if (e == i) continue;
      dfs(dfs, j, e);
    }

    *it = p;
  };
  dfs(dfs, 0, 0);

  for (auto e : r) cout << e << endl;
}
