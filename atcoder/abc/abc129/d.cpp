#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (auto &e : s) cin >> e;

  vector<vector<int>> u, d, l, r(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      r[i][j] = s[i][j] == '.';
    }
  }
  u = d = l = r;

  for (int i = 1; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (u[i][j]) u[i][j] += u[i - 1][j];
    }
  }
  for (int i = h - 2; i >= 0; i--) {
    for (int j = 0; j < w; j++) {
      if (d[i][j]) d[i][j] += d[i + 1][j];
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 1; j < w; j++) {
      if (l[i][j]) l[i][j] += l[i][j - 1];
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = w - 2; j >= 0; j--) {
      if (r[i][j]) r[i][j] += r[i][j + 1];
    }
  }

  int m = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      m = max(m, u[i][j] + d[i][j] + l[i][j] + r[i][j] - 3);
    }
  }
  cout << m << endl;
}
