#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(n);
  for (auto &e : a) {
    cin >> e;
  }
  set<int> s;
  for (auto e : a) {
    s.insert(e);
  }

  int m = *rbegin(s) - *begin(s);
  for (auto x : s) {
    vector<vector<int>> v(1);
    for (auto e : a) {
      if (e < x) {
        if (v.back().size()) {
          v.push_back(vector<int>());
        }
      } else {
        v.back().push_back(e);
      }
    }
    vector<int> r;
    for (auto &e : v) {
      sort(begin(e), end(e));
      for (int i = 0; i < (int)e.size() - (k - 1); i++) {
        r.push_back(e[i]);
      }
    }
    if (r.size() >= q) {
      sort(begin(r), end(r));
      m = min(m, r[q - 1] - r[0]);
    }
  }
  cout << m << endl;
  return 0;
}
