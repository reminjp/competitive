#include <bits/stdc++.h>
using namespace std;
#define EPS (1e-3)
typedef complex<double> P;

double dot(P a, P b) { return a.real() * b.real() + a.imag() * b.imag(); }

double cross(P a, P b) { return a.real() * b.imag() - a.imag() * b.real(); }

double distance(P s1, P s2, P p) {
  if (dot(s2 - s1, p - s1) < EPS) return abs(p - s1);
  if (dot(s1 - s2, p - s2) < EPS) return abs(p - s2);
  return abs(cross(s2 - s1, p - s1)) / abs(s2 - s1);
}

bool is_intersected(P a1, P a2, P b1, P b2) {
  return cross(a2 - a1, b1 - a1) * cross(a2 - a1, b2 - a1) < -EPS &&
         cross(b2 - b1, a1 - b1) * cross(b2 - b1, a2 - b1) < -EPS;
}

int main() {
  int n;
  while (cin >> n, n) {
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    P s(sx, sy), e(ex, ey);
    double m = 1e3;
    for (int i = 0; i < n; i++) {
      int minx, miny, maxx, maxy, h;
      cin >> minx >> miny >> maxx >> maxy >> h;
      vector<P> v = {P(minx, miny), P(minx, maxy), P(maxx, miny), P(maxx, maxy)};
      double d = 1e3;
      for (auto p1 : v) {
        for (auto p2 : v) {
          if (abs(p2 - p1) < EPS) {
            continue;
          }
          if (is_intersected(s, e, p1, p2)) {
            d = 0;
          }
        }
      }
      for (auto p1 : v) {
        d = min(d, distance(s, e, p1));
        for (auto p2 : v) {
          d = min(d, distance(p1, p2, s));
          d = min(d, distance(p1, p2, e));
        }
        m = min(m, d < h ? d : (d * d + h * h) / (2 * h));
      }
    }
    cout << fixed << setprecision(4) << m << endl;
  }
}
