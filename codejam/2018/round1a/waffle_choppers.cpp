#include <bits/stdc++.h>
using namespace std;

void solve() {
  int r, c, h, v;
  cin >> r >> c >> h >> v;
  vector<vector<int>> a(r + 1, vector<int>(c + 1));
  for (int i = 0; i < r; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < c; j++) {
      a[i + 1][j + 1] = s[j] == '@';
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      a[i + 1][j + 1] += a[i + 1][j] + a[i][j + 1] - a[i][j];
    }
  }

  bool b;
  if (a[r][c] == 0) {
    b = true;
  } else if (a[r][c] % ((h + 1) * (v + 1))) {
    b = false;
  } else {
    vector<int> y{0};
    for (int i = 0; i < r; i++) {
      if (a[i + 1][c] - a[y.back()][c] == a[r][c] / (h + 1)) {
        y.push_back(i + 1);
      }
    }
    vector<int> x{0};
    for (int i = 0; i < c; i++) {
      if (a[r][i + 1] - a[r][x.back()] == a[r][c] / (v + 1)) {
        x.push_back(i + 1);
      }
    }
    b = y.size() == h + 2 && x.size() == v + 2;
    for (int i = 0; i < y.size() - 1; i++) {
      for (int j = 0; j < x.size() - 1; j++) {
        b &= a[y[i + 1]][x[j + 1]] - a[y[i + 1]][x[j]] - a[y[i]][x[j + 1]] +
                 a[y[i]][x[j]] ==
             a[r][c] / ((h + 1) * (v + 1));
      }
    }
  }
  cout << (b ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
