#include <bits/stdc++.h>
using namespace std;

int main() {
  int d, g;
  cin >> d >> g;
  vector<int> p(d), c(d);
  for (int i = 0; i < d; i++) {
    cin >> p[i] >> c[i];
  }

  int r = 1e9;
  for (int b = 0; b < 1 << d; b++) {
    int m = 0, s = 0;
    for (int i = 0; i < d; i++) {
      if ((b & 1 << i) != 0) {
        m += p[i];
        s += 100 * (i + 1) * p[i] + c[i];
      }
    }
    for (int i = d - 1; i >= 0 && s < g; i--) {
      if ((b & 1 << i) == 0) {
        int x;
        if (s + 100 * (i + 1) * (p[i] - 1) < g) {
          x = p[i] - 1;
        } else {
          x = (g - s - 1) / (100 * (i + 1)) + 1;
        }
        m += x;
        s += 100 * (i + 1) * x;
      }
    }
    if (s >= g) {
      r = min(r, m);
    }
  }

  cout << r << endl;
}
