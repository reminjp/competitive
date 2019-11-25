#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  string t0;
  cout << "? ";
  for (int i = 0; i < n; i++) cout << i + 1 << ' ';
  cout << endl;
  cin >> t0;

  int l = 0, r = n;
  while (l + 1 < r) {
    int m = l + (r - l) / 2;
    cout << "? ";
    for (int i = 0; i < n; i++) cout << m + i + 1 << ' ';
    cout << endl;
    string t;
    cin >> t;
    if (t == t0) {
      l = m;
    } else {
      r = m;
    }
  }

  string c(2 * n, '.');
  for (int i = 0; i < 2 * n; i++) {
    cout << "? " << i + 1 << ' ';
    if (l <= i && i < l + n) {
      for (int j = 0; j < n - 1; j++) cout << ((l + n + 1) + j) % (2 * n) + 1 << ' ';
    } else {
      for (int j = 0; j < n - 1; j++) cout << (l + 1) + j + 1 << ' ';
    }
    cout << endl;
    string t;
    cin >> t;
    c[i] = "BR"[t[0] == 'R'];
  }
  cout << "! " << c << endl;
}
