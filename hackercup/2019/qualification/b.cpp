#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  cin >> s;
  int b = 0;
  for (auto e : s) b += e == 'B';
  cout << "NY"[min(2, (int)s.size() / 2) <= b && b < s.size() - 1] << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
