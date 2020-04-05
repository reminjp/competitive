#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  cin >> s;
  int d = 0;
  for (auto e : s) {
    int de = e - '0';
    if (de > d) cout << string(de - d, '(');
    if (de < d) cout << string(d - de, ')');
    cout << e;
    d = de;
  }
  cout << string(s.back() - '0', ')') << '\n';
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
