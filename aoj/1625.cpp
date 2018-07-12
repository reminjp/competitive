#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, t, p;
  while (cin >> n >> m >> t >> p, n) {
    vector<pair<int, int>> d(t), x(p);
    for (auto &e : d) cin >> e.first >> e.second;
    for (auto &e : x) cin >> e.first >> e.second;

    vector<vector<int>> a((t + 1) * m, vector<int>((t + 1) * n));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = 1;
      }
    }
    int x0 = 0, y0 = 0;
    for (auto e : d) {
      if (e.first == 1) {
        x0 += e.second;
        for (int i = 0; a[y0 + i][x0]; i++) {
          for (int j = 0; x0 - j - 1 >= 0 && (a[y0 + i][x0 + j] || a[y0 + i][x0 - j - 1]); j++) {
            a[y0 + i][x0 + j] += a[y0 + i][x0 - j - 1];
            a[y0 + i][x0 - j - 1] = 0;
          }
        }
      } else {
        y0 += e.second;
        for (int j = 0; a[y0][x0 + j]; j++) {
          for (int i = 0; y0 - i - 1 >= 0 && (a[y0 + i][x0 + j] || a[y0 - i - 1][x0 + j]); i++) {
            a[y0 + i][x0 + j] += a[y0 - i - 1][x0 + j];
            a[y0 - i - 1][x0 + j] = 0;
          }
        }
      }
    }

    for (auto e : x) {
      cout << a[y0 + e.second][x0 + e.first] << endl;
    }
  }
}
