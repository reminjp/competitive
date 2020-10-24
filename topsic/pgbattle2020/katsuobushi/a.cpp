#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int r = 0;
  auto dfs = [&](auto&& dfs, int i, int j) -> void {
    int c = 0;
    for (auto e : g[j]) {
      if (e == i) continue;
      dfs(dfs, j, e);
      c++;
    }
    if (c == 0) r++;
  };
  dfs(dfs, 0, 0);

  cout << r << endl;
}
