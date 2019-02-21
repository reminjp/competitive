#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  for (auto &e : a) {
    cin >> e;
  }
  for (auto &e : b) {
    cin >> e;
  }
  int r = 0;
  if (n < m) {
    r = -1;
  } else if (n > m) {
    r = 1;
  } else {
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        r = a[i] - b[i];
        break;
      }
    }
  }
  cout << (r < 0 ? "X" : r > 0 ? "Y" : "Same") << endl;
}
