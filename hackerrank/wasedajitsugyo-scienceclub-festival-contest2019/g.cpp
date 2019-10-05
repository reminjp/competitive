#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n);
  int root;
  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    if (w - 1 == i) {
      root = i;
    } else {
      graph[w - 1].push_back(i);
    }
  }

  vector<int> order_to_index(n), index_to_order(n), subtree_end(n);
  {
    int o = 0;
    function<void(int)> dfs = [&](int i) {
      order_to_index[o] = i;
      index_to_order[i] = o;
      o++;
      for (auto j : graph[i]) dfs(j);
      subtree_end[index_to_order[i]] = o;
    };
    dfs(root);
  }

  vector<vector<ll>> s(n + 1, vector<ll>(n + 1));
  for (; m > 0; m--) {
    int a, b, c;
    cin >> a >> b >> c;
    int ao = index_to_order[a - 1], bo = index_to_order[b - 1];
    if (ao > bo) swap(ao, bo);
    int ae = subtree_end[ao], be = subtree_end[bo];
    s[ao][bo] += c;
    s[ao][be] += -c;
    s[ae][bo] += -c;
    s[ae][be] += c;
    s[bo][ao] += c;
    s[bo][ae] += -c;
    s[be][ao] += -c;
    s[be][ae] += c;
    if (be <= ae) {
      s[bo][bo] += 2 * -c;
      s[bo][be] += 2 * c;
      s[be][bo] += 2 * c;
      s[be][be] += 2 * -c;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      s[i + 1][j] += s[i][j];
      s[i][j + 1] += s[i][j];
      s[i + 1][j + 1] -= s[i][j];
    }
  }

  vector<int> r(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[index_to_order[i]][index_to_order[j]] > s[index_to_order[i]][index_to_order[r[i]]]) r[i] = j;
    }
  }
  for (auto e : r) cout << e + 1 << ' ';
  cout << endl;
}
