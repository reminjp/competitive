#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w)), b(h, vector<int>(w));
  for (auto& v : a) {
    for (auto& e : v) cin >> e;
  }
  for (auto& v : b) {
    for (auto& e : v) cin >> e;
  }

  int m = 80 * 80 + 1;
  vector<vector<vector<bool>>> s(h + 1, vector<vector<bool>>(w + 1, vector<bool>(m)));
  s[0][0][0] = true;
  s[0][1][0] = true;
  s[1][0][0] = true;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int d = abs(a[i][j] - b[i][j]);
      for (int k = 0; k < m; k++) {
        if (!s[i + 1][j][k]) continue;
        if (abs(k + d) < m) s[i + 1][j + 1][abs(k + d)] = true;
        if (abs(k - d) < m) s[i + 1][j + 1][abs(k - d)] = true;
      }
      for (int k = 0; k < s[i][j + 1].size(); k++) {
        if (!s[i][j + 1][k]) continue;
        if (abs(k + d) < m) s[i + 1][j + 1][abs(k + d)] = true;
        if (abs(k - d) < m) s[i + 1][j + 1][abs(k - d)] = true;
      }
    }
  }
  cout << find(s[h][w].begin(), s[h][w].end(), true) - s[h][w].begin() << endl;
}
