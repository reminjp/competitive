#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(q), b(q), c(q), d(q);
  for (int i = 0; i < q; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--;
    b[i]--;
  }

  vector<int> v;
  auto dfs = [&](auto&& dfs) {
    int r = 0;
    if (v.size() == n) {
      for (int i = 0; i < q; i++) {
        if (v[b[i]] - v[a[i]] == c[i]) r += d[i];
      }
      return r;
    }
    for (int i = (v.empty() ? 1 : v.back()); i <= m; i++) {
      v.push_back(i);
      r = max(r, dfs(dfs));
      v.pop_back();
    }
    return r;
  };
  cout << dfs(dfs) << endl;
}
