#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> a(n), b(n), c(n, string(n, '1'));
  for (auto &e : a) cin >> e;
  for (auto &e : b) cin >> e;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (a[i][j] == '1' && b[i][k] == '0') c[j][k] = '0';
      }
    }
  }

  bool r = true;
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      bool t = false;
      for (int j = 0; j < n; j++) {
        t |= a[i][j] == '1' && c[j][k] == '1';
      }
      r &= t == (b[i][k] == '1');
    }
  }
  if (r) {
    for (const auto &e : c) cout << e << endl;
  } else {
    cout << -1 << endl;
  }
}
