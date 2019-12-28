#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> children(n);
  int root = 0;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    if (e == -1) {
      root = i;
    } else {
      children[e - 1].push_back(i);
    }
  }

  vector<pair<int, int>> segments(n);
  int p = 0;
  auto dfs = [&](auto&& dfs, int i) -> void {
    segments[i].first = p;
    for (int j : children[i]) {
      dfs(dfs, j);
    }
    p++;
    segments[i].second = p;
  };
  dfs(dfs, root);

  int q;
  cin >> q;
  for (; q > 0; q--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    cout << (segments[b].first <= segments[a].first && segments[a].second < segments[b].second ? "Yes" : "No") << endl;
  }
}
