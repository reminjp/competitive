#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> v(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    v[a - 1].push_back(b - 1);
    v[b - 1].push_back(a - 1);
  }
  vector<int> r(n);
  for (int i = 0; i < q; i++) {
    int p, x;
    cin >> p >> x;
    r[p - 1] += x;
  }
  function<void(int, int)> dfs = [&](int i, int j) {
    for (auto e : v[j]) {
      if (e == i) continue;
      r[e] += r[j];
      dfs(j, e);
    }
  };
  dfs(0, 0);
  for (auto e : r) cout << e << ' ';
  cout << endl;
}
