#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int e;
      cin >> e;
      a[i][j] = e;
    }
  }

  auto f = [&](int g) {
    int s = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if ((g >> i & 1) && (g >> j & 1)) s += a[i][j];
      }
    }
    return s;
  };

  int r = -1e9;
  for (int g1 = 0; g1 < (1 << n); g1++) {
    for (int g2 = 0; g2 < (1 << n); g2++) {
      if (g1 & g2) continue;
      int g3 = (1 << n) - 1 ^ (g1 | g2);
      r = max(r, f(g1) + f(g2) + f(g3));
    }
  }
  cout << r << endl;
}
