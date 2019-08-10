#include <bits/stdc++.h>
using namespace std;
constexpr int inf = 1e9;

int main() {
  int n, m, p;
  cin >> n >> m >> p;
  vector<vector<pair<int, int>>> v(n);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a - 1].push_back({b - 1, c - p});
  }

  vector<bool> is_parent(n);
  vector<int> s(n, -1e9);
  s[0] = 0;
  function<void(int)> dfs = [&](int i) {
    is_parent[i] = true;
    for (auto e : v[i]) {
      if (s[e.first] < min(inf, s[i] + e.second)) {
        s[e.first] = is_parent[e.first] || s[i] == inf ? inf : s[i] + e.second;
        dfs(e.first);
      }
    }
    is_parent[i] = false;
  };
  dfs(0);

  cout << (s[n - 1] == inf ? -1 : max(0, s[n - 1])) << endl;
}
