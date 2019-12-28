#include <bits/stdc++.h>
using namespace std;
constexpr double INF = 1e9;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> x(n + m), y(n + m), c(n + m);
  for (int i = 0; i < n + m; i++) cin >> x[i] >> y[i] >> c[i];

  vector<vector<double>> d(n + m, vector<double>(n + m));
  for (int i = 0; i < n + m; i++) {
    for (int j = 0; j < n + m; j++) {
      d[i][j] = sqrt(pow(x[j] - x[i], 2) + pow(y[j] - y[i], 2));
      if (c[i] != c[j]) d[i][j] *= 10;
    }
  }

  double r = INF;
  for (int b = 0; b < (1 << m); b++) {
    vector<double> min_d = d[0];
    min_d[0] = INF;
    for (int i = 0; i < m; i++) {
      if (!(b >> i & 1)) min_d[n + i] = INF;
    }

    double rb = 0;
    int count = n - 1 + bitset<5>(b).count();
    while (count) {
      int i = min_element(min_d.begin(), min_d.end()) - min_d.begin();
      rb += min_d[i];
      min_d[i] = INF;
      for (int j = 0; j < n + m; j++) {
        if (min_d[j] != INF) min_d[j] = min(min_d[j], d[i][j]);
      }
      count--;
    }
    r = min(r, rb);
  }
  cout << fixed << setprecision(7);
  cout << r << endl;
}
