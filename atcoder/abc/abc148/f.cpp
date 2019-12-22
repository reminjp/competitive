#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(const vector<vector<int>>& g, int s) {
  vector<int> d(g.size(), 1e9);
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    for (auto j : g[i]) {
      if (d[i] + 1 < d[j]) {
        d[j] = d[i] + 1;
        q.push(j);
      }
    }
  }
  return d;
}

int main() {
  int n, u, v;
  cin >> n >> u >> v;
  u--, v--;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  auto du = bfs(g, u);
  auto dv = bfs(g, v);
  int r = 0;
  for (int i = 0; i < n; i++) {
    if (du[i] > dv[i]) continue;
    r = max(r, dv[i] - 1);
  }
  cout << r << endl;
}
