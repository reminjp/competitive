#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (auto &e : a) cin >> e;
  for (auto &e : b) cin >> e;

  vector<int> r;
  map<int, pair<int, int>> p;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (p.count(a[i] + b[j])) {
        if (p[a[i] + b[j]].first != i) {
          r = vector<int>{p[a[i] + b[j]].first, p[a[i] + b[j]].second, i, j};
          break;
        }
      } else {
        p[a[i] + b[j]] = make_pair(i, j);
      }
    }
  }

  if (r.empty()) {
    cout << -1 << endl;
  } else {
    for (auto e : r) cout << e << ' ';
    cout << endl;
  }
}
