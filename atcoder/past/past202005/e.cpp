#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> c(n);
  for (auto& e : c) cin >> e;
  while (q--) {
    int s, x, y;
    cin >> s >> x;
    x--;
    cout << c[x] << endl;
    if (s == 1) {
      for (auto e : g[x]) c[e] = c[x];
    } else {
      cin >> y;
      c[x] = y;
    }
  }
}
