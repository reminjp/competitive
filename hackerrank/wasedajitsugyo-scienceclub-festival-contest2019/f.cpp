#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  vector<vector<int>> v(n);
  for (int i = 0; i < m; i++) {
    int p, q;
    cin >> p >> q;
    v[p - 1].push_back(q - 1);
  }

  function<ll(int)> dfs = [&](int i) {
    ll r = a[i];
    for (auto j : v[i]) r = max(r, b[i] + dfs(j));
    return r;
  };
  cout << dfs(0) << endl;
}
