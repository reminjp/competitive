#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> graph(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  vector<vector<int>> colored_nodes(2);
  auto dfs = [&](auto&& dfs, int i, int j, int d) -> void {
    colored_nodes[d % 2].push_back(j);
    for (auto k : graph[j]) {
      if (k == i) continue;
      dfs(dfs, j, k, d + 1);
    }
  };
  dfs(dfs, 0, 0, 0);
  if (colored_nodes[0].size() > colored_nodes[1].size()) swap(colored_nodes[0], colored_nodes[1]);

  int m = colored_nodes[0].size();
  vector<int> r(n);
  for (int i = 1; i <= n; i++) {
    int k;
    if (m <= n / 3) {
      if (i % 3 == 0) {
        k = colored_nodes[0].empty() ? 1 : 0;
      } else {
        k = 1;
      }
    } else {
      if (i % 3 == 0) {
        k = colored_nodes[0].size() < colored_nodes[1].size() ? 1 : 0;
      } else if (i % 3 == 1) {
        k = 1;
      } else if (i % 3 == 2) {
        k = 0;
      }
    }
    r[colored_nodes[k].back()] = i;
    colored_nodes[k].pop_back();
  }

  for (auto e : r) cout << e << ' ';
  cout << endl;
}
