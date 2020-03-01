#include <bits/stdc++.h>
using namespace std;

#define EPS (1e-9)
#define EQ(a, b) (abs((a) - (b)) < EPS)

typedef complex<double> Vector2;

vector<Vector2> CircleIntersections(Vector2 a, Vector2 b, double ra, double rb) {
  double d = abs(b - a);
  if (ra + rb < d) return {};
  double c = acos((ra * ra + d * d - rb * rb) / (2 * ra * d));
  double t = atan2(b.imag() - a.imag(), b.real() - a.real());
  Vector2 p1 = a + Vector2(cos(t + c) * ra, sin(t + c) * ra);
  Vector2 p2 = a + Vector2(cos(t - c) * ra, sin(t - c) * ra);
  return {p1, p2};
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<Vector2> v(n);
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y >> c[i];
    v[i] = Vector2(x, y);
  }
  if (k == 1) {
    cout << 0 << endl;
    return 0;
  }

  double r = 1e9;
  for (int top0 = 1; top0 < 1e9; top0 *= 10) {
    double bot = 0, top = top0, mid;
    while (!EQ(bot, top)) {
      mid = bot + (top - bot) / 2;
      bool valid = false;
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          auto u = CircleIntersections(v[i], v[j], mid / c[i], mid / c[j]);
          //
          if (!u.empty()) u.push_back((u[0] + u[1]) / 2.0);
          //
          for (auto e : u) {
            int x = 2;
            for (int l = 0; l < n; l++) {
              if (l == i || l == j) continue;
              x += abs(e - v[l]) <= mid / c[l];
            }
            if (x >= k) valid = true;
          }
        }
      }
      if (valid) {
        top = mid;
      } else {
        bot = mid;
      }
    }
    if (!EQ(top, top0)) r = min(r, bot);
  }
  cout << fixed << setprecision(9);
  cout << r << endl;
}
