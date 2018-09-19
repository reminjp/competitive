#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<double>> a(n, vector<double>(3));
  for (auto &r : a) {
    for (auto &e : r) {
      cin >> e;
    }
  }
  vector<vector<double>> d(n, vector<double>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 3; k++) {
        d[i][j] += (a[i][k] - a[j][k]) * (a[i][k] - a[j][k]);
      }
    }
  }
  vector<int> v(n);
  fill(rbegin(v), rbegin(v) + m, 1);
  double r = 0;
  do {
    double t = 0;
    for (int i = 0; i < n; i++) {
      if (v[i]) {
        for (int j = i + 1; j < n; j++) {
          if (v[j]) {
            t += d[i][j];
          }
        }
      }
    }
    r = max(r, t);
  } while (next_permutation(begin(v), end(v)));
  cout << fixed << setprecision(6) << r << endl;
}
