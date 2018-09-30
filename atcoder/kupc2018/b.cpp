#include <bits/stdc++.h>
using namespace std;

int main() {
  string impossible = "impossible";
  int h, w;
  cin >> h >> w;
  vector<string> c(h);
  for (auto &e : c) {
    cin >> e;
  }
  vector<vector<string>> r(h, vector<string>(w));
  for (int j = 0; j < w; j++) {
    r[h - 1][j] = c[h - 1][j] == 's' ? "" : impossible;
  }
  for (int i = h - 2; i >= 0; i--) {
    for (int j = 0; j < w; j++) {
      r[i][j] = impossible;
      if (c[i][j] != 'x') {
        if (r[i + 1][j] != impossible) {
          r[i][j] = r[i + 1][j] + "S";
        } else if (0 <= j - 1 && r[i + 1][j - 1] != impossible) {
          r[i][j] = r[i + 1][j - 1] + "R";
        } else if (j + 1 < w && r[i + 1][j + 1] != impossible) {
          r[i][j] = r[i + 1][j + 1] + "L";
        }
      }
    }
  }
  string t = impossible;
  for (auto e : r[0]) {
    if (e != impossible) {
      t = e;
      break;
    }
  }
  cout << t << endl;
}
