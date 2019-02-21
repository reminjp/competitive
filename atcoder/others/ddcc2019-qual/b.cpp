#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<bool>> v(n + 1, vector<bool>(n + 1));
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      int id = n - i, jd = n - j;
      v[i][j] = 2 * (i + j) >= n && 2 * (i + jd) >= n && 2 * (id + j) >= n && 2 * (id + jd) >= n;
    }
  }
  int r = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      r += v[i][j] && v[i][j + 1] && v[i + 1][j] && v[i + 1][j + 1];
    }
  }
  cout << r << endl;
}
