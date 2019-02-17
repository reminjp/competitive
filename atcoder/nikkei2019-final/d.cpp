#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<set<int>> l(n), r(n);
  for (int i = 0; i < m; i++) {
    int ti, li, ri;
    cin >> ti >> li >> ri;
    l[li - 1].insert(ti);
    r[ri - 1].insert(ti);
  }
  ll s = 0;
  set<int> t;
  for (int i = 0; i < n; i++) {
    for (auto e : l[i]) {
      t.insert(e);
    }
    if (!t.empty()) {
      s += *rbegin(t);
    }
    for (auto e : r[i]) {
      t.erase(e);
    }
  }
  cout << s << endl;
}
