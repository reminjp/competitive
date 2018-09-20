#include <bits/stdc++.h>
using namespace std;

#define EPS (1e-6)
#define EQ(a, b) (abs((a) - (b)) < EPS)

typedef complex<double> vector2;
typedef pair<vector2, vector2> line;

double dot(vector2 a, vector2 b) { return real(conj(a) * b); }
double cross(vector2 a, vector2 b) { return imag(conj(a) * b); }

vector<vector2> circle_intersections(vector2 a, vector2 b, double r) {
  double d = abs(b - a);
  if (2 * r < d) return {};
  double rc = d / 2;
  double rs = sqrt(r * r - rc * rc);
  vector2 diff = (b - a) / d;
  return {a + diff * vector2(rc, rs), a + diff * vector2(rc, -rs)};
}

int main() {
  int n, m;
  cin >> n;
  vector<vector2> p(n);
  for (auto &e : p) {
    double x, y;
    cin >> x >> y;
    e = {x, y};
  }
  cin >> m;
  vector<vector2> c(m);
  for (auto &e : c) {
    double x, y;
    cin >> x >> y;
    e = {x, y};
  }

  double ng = 0, ok = 1e6, r;
  while (ng + EPS < ok) {
    r = (ng + ok) / 2.0;
    bool isok = true;

    vector<int> v(n, -1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (abs(c[j] - p[i]) < r) {
          v[i] = j;
          break;
        }
      }
      if (v[i] == -1) {
        isok = false;
      }
    }

    if (isok) {
      vector<vector<bool>> g(m, vector<bool>(m));
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
          if (abs(c[j] - c[i]) < 2 * r) {
            g[i][j] = true;
          }
        }
      }
      for (int k = 0; k < m; k++) {
        for (int i = 0; i < m; i++) {
          for (int j = 0; j < m; j++) {
            if (g[i][k] && g[k][j]) {
              g[i][j] = true;
            }
          }
        }
      }

      for (int i = 0; i < m; i++) {
        isok &= g[0][i];
      }
    }

    if (isok) {
      vector<vector2> u;
      for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
          vector<vector2> w = circle_intersections(c[i], c[j], r);
          for (auto e : w) {
            bool outer = true;
            for (int k = 0; k < m; k++) {
              if (k == i || k == j) {
                continue;
              }
              outer &= abs(e - c[k]) > r;
            }
            if (outer) {
              u.push_back(e);
            }
          }
        }
      }

      for (auto e : u) {
        double t = 0;
        for (int i = 0; i < n; i++) {
          int j = (i + 1) % n;
          vector2 a = p[i] - e, b = p[j] - e;
          t += atan2(cross(a, b), dot(a, b));
        }
        if (!EQ(t, 0)) {
          isok = false;
          break;
        }
      }
    }

    if (isok) {
      ok = r;
    } else {
      ng = r;
    }
  }

  cout << fixed << setprecision(6) << r << endl;
}
