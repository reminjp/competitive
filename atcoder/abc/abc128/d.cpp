#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (auto &e : v) cin >> e;

  vector<vector<int>> dpl(n + 1, vector<int>(n + 1, -1e9)), dpr(n + 1, vector<int>(n + 1, -1e9));
  dpl[0][0] = dpr[0][0] = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      dpl[i][j] = dpl[i - 1][j];
      if (j) dpl[i][j] = max(dpl[i][j], dpl[i - 1][j - 1] + v[i - 1]);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      dpr[i][j] = dpr[i - 1][j];
      if (j) dpr[i][j] = max(dpr[i][j], dpr[i - 1][j - 1] + v[n - i]);
    }
  }

  int m = 0;
  for (int l = 0; l <= k; l++) {
    for (int lp = 0; l + lp <= k && lp <= l; lp++) {
      for (int r = 0; l + lp + r <= k && l + r <= n; r++) {
        for (int rp = 0; l + lp + r + rp <= k && rp <= r; rp++) {
          m = max(m, dpl[l][l - lp] + dpr[r][r - rp]);
        }
      }
    }
  }
  cout << m << endl;
}
