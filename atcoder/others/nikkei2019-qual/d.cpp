#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n), u(n);
  vector<int> k(n);
  for (int i = 0; i < n - 1 + m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    v[a].push_back(b);
    u[b].push_back(a);
    k[b]++;
  }

  vector<int> r(n), d(n), l, s;
  for (int i = 0; i < n; i++) {
    if (k[i] == 0) s.push_back(i);
  }
  while (!s.empty()) {
    int i = s.back();
    s.pop_back();
    l.push_back(i);
    for (auto e : v[i]) {
      k[e]--;
      if (k[e] == 0) {
        s.push_back(e);
      }
    }
  }

  for (int i = 1; i < l.size(); i++) {
    int x = l[i];
    int y = u[x].front();
    for (auto e : u[x]) {
      if (d[e] > d[y]) {
        y = e;
      }
    }
    d[x] = d[y] + 1;
    r[x] = y + 1;
  }
  for (auto e : r) {
    cout << e << endl;
  }
}
