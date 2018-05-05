#include <bits/stdc++.h>
using namespace std;

string serach(const set<string>& s, const vector<map<char, int>>& c, string t) {
  if (t.size() == c.size()) {
    if (s.count(t)) {
      return "";
    } else {
      return t;
    }
  }
  for (auto e : c[t.size()]) {
    t.push_back(e.first);
    string r = serach(s, c, t);
    if (r != "") {
      return r;
    }
    t.pop_back();
  }
  return "";
}

void solve() {
  int n, l;
  cin >> n >> l;
  vector<string> w(n);
  set<string> s;
  for (auto& e : w) {
    cin >> e;
    s.insert(e);
  }
  vector<map<char, int>> c(l, map<char, int>());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < l; j++) {
      c[j][w[i][j]]++;
    }
  }
  int m = 1;
  for (auto e : c) {
    m = min(2001, m * (int)e.size());
  }
  string t;
  if (n == m) {
    t = "-";
  } else {
    t = serach(s, c, "");
  }
  cout << t << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
