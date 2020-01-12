#include <bits/stdc++.h>
using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (auto& e : s) cin >> e;

  int n = h * w;
  vector<vector<int>> d(n, vector<int>(n, 1e9));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') continue;
      if (i + 1 < h && s[i + 1][j] != '#') d[i * w + j][(i + 1) * w + j] = d[(i + 1) * w + j][i * w + j] = 1;
      if (j + 1 < w && s[i][j + 1] != '#') d[i * w + j][i * w + (j + 1)] = d[i * w + (j + 1)][i * w + j] = 1;
    }
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
      }
    }
  }

  int r = 0;
  for (int i = 0; i < n; i++) {
    if (s[i / w][i % w] == '#') continue;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (s[j / w][j % w] == '#') continue;
      r = max(r, d[i][j]);
    }
  }
  cout << r << endl;
}
