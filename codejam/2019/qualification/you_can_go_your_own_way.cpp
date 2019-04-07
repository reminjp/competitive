#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  string s, r;
  cin >> n >> s;
  for (auto e : s) {
    r.push_back(e == 'E' ? 'S' : 'E');
  }
  cout << r << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
