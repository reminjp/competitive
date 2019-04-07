#include <bits/stdc++.h>
using namespace std;

void solve() {
  string n;
  cin >> n;
  string a, b;
  for (int i = 0; i < n.size(); i++) {
    if (n[i] == '4') {
      a.push_back('2');
      b.push_back('2');
    } else {
      a.push_back(n[i]);
      if (!b.empty()) b.push_back('0');
    }
  }
  cout << a << " " << b << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
