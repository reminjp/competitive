#include <bits/stdc++.h>
using namespace std;

int main() {
  string d = "LURD";

  int h, w, n, sr, sc;
  vector<string> s(2);
  cin >> h >> w >> n >> sr >> sc >> s[0] >> s[1];
  vector<int> l = {sc - 1, sr - 1, w - sc, h - sr};

  vector<vector<vector<int>>> v(n + 1, vector<vector<int>>(4, vector<int>(2)));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 2; k++) {
        v[i + 1][j][k] = v[i][j][k] + (s[k][i] == d[j]);
      }
    }
    for (int j = 0; j < 4; j++) {
      v[i + 1][j][1] = min(v[i + 1][j][1], v[i + 1][(j + 2) % 4][0] + l[j]);
    }
  }

  bool r = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      r &= v[i + 1][j][0] - v[i][(j + 2) % 4][1] <= l[j];
    }
  }
  cout << (r ? "YES" : "NO") << endl;
}
