#include <bits/stdc++.h>
using namespace std;
#define EPS (1e-4)
typedef complex<double> P;

int main() {
  int n;
  while (cin >> n, n) {
    vector<P> a(n);
    for (auto &e : a) {
      double x, y;
      cin >> x >> y;
      e.real(x);
      e.imag(y);
    }
    int m = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i != j && abs(a[j] - a[i]) < 2.0 + EPS) {
          P u = (a[j] - a[i]) / 2.0;
          P v = P(-u.imag(), u.real()) / abs(u) * sqrt(1.0 - pow(abs(u), 2));
          vector<P> o = {a[i] + u + v, a[i] + u - v};
          for (auto e : o) {
            int t = 2;
            for (int k = 0; k < n; k++) {
              if (k != i && k != j) {
                t += abs(a[k] - e) < 1.0 + EPS;
              }
            }
            m = max(m, t);
          }
        }
      }
    }
    cout << m << endl;
  }
}
