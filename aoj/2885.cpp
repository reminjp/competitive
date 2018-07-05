#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m, n) {
    vector<vector<int>> v(n, vector<int>());
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      v[a].push_back(b);
      v[b].push_back(a);
    }

    bool bi = true;
    vector<bool> u(n), c(n);
    u[0] = true;
    stack<int> s;
    s.push(0);
    while (!s.empty()) {
      int t = s.top();
      s.pop();
      for (auto e : v[t]) {
        if (!u[e]) {
          u[e] = true;
          c[e] = !c[t];
          s.push(e);
        } else if (c[e] == c[t]) {
          bi = false;
        }
      }
    }

    vector<int> m(2);
    if (bi) {
      for (auto e : c) {
        m[e]++;
      }
    }
    set<int> r;
    for (auto e : m) {
      if (e > 0 && e % 2 == 0) {
        r.insert(e / 2);
      }
    }

    cout << r.size() << endl;
    for (auto e : r) {
      cout << e << endl;
    }
  }
}
