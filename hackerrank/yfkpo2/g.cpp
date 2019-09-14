#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int h, w, q;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w)), d(h + 1, vector<int>(w + 1));
  for (auto &ai : a) {
    for (auto &aij : ai) cin >> aij;
  }
  cin >> q;
  for (q *= 2; q > 0; q--) {
    int y1, y2, x1, x2;
    cin >> y1 >> y2 >> x1 >> x2;
    y1--;
    x1--;
    d[y1][x1]++;
    d[y1][x2]++;
    d[y2][x1]++;
    d[y2][x2]++;
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      d[i][j + 1] += d[i][j];
      d[i + 1][j] += d[i][j];
      d[i + 1][j + 1] -= d[i][j];
    }
  }
  // for (int i = 0; i < h; i++) {
  //   for (int j = 0; j < w; j++) cerr << d[i][j] << ' ';
  //   cerr << endl;
  // }
  int r = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (d[i][j] % 2) r += a[i][j];
    }
  }
  cout << r << endl;
}
