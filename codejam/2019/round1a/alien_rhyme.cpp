#include <bits/stdc++.h>
using namespace std;

string longest_common_prefix(const string &a, const string &b) {
  int n = min(a.size(), b.size());
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      return a.substr(0, i);
    }
  }
  return a.substr(0, n);
}

void solve() {
  int n;
  cin >> n;
  vector<string> w(n);
  for (auto &e : w) {
    cin >> e;
    reverse(begin(e), end(e));
  }
  sort(begin(w), end(w));
  set<string> u;
  while (true) {
    string pm;
    int im = -1;
    for (int i = 0; i < (int)w.size() - 1; i++) {
      string p = longest_common_prefix(w[i], w[i + 1]);
      while (!p.empty() && u.count(p)) p.pop_back();
      if (p.size() > pm.size()) {
        pm = p;
        im = i;
      }
    }
    if (im == -1) break;
    u.insert(pm);
    w.erase(begin(w) + im);
    w.erase(begin(w) + im);
  }
  cout << n - w.size() << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
