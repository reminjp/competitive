#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  vector<int> v;
  for (auto& e : a) {
    cin >> e.first >> e.second;
    e.first--, e.second--;
    v.push_back(e.first);
  }
  sort(a.begin(), a.end());

  dsu d(n);
  set<pair<int, int>> s;
  for (auto e : a) {
    bool b = true;
    if (e.first > 0) {
      auto it = s.lower_bound({e.second, e.first});
      while (it != s.begin()) {
        it--;
        d.merge(it->second, e.first);
        b = false;
      }
    }
    if (b) {
      s.insert({e.second, e.first});
    }
  }

  for (int i = 0; i < n; i++) cout << d.size(v[i]) << endl;
}
