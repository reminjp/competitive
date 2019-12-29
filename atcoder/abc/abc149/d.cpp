#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, r, s, p;
  string t;
  cin >> n >> k >> r >> s >> p >> t;

  int a = 0;
  string u(n, '.');
  for (int i = 0; i < n; i++) {
    switch (t[n - 1 - i]) {
      case 'r': {
        if (i < k || i - k >= 0 && u[i - k] != 'p') {
          a += p;
          u[i] = 'p';
        }
        break;
      }
      case 's': {
        if (i < k || i - k >= 0 && u[i - k] != 'r') {
          a += r;
          u[i] = 'r';
        }
        break;
      }
      case 'p': {
        if (i < k || i - k >= 0 && u[i - k] != 's') {
          a += s;
          u[i] = 's';
        }
        break;
      }
    }
  }
  cout << a << endl;
}
