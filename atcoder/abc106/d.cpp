#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> a(n + 1, vector<int>(n + 1));
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    a[l][r]++;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i + 1][j + 1] += a[i + 1][j];
    }
  }

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    int m = 0;
    for (int j = l; j <= r; j++) {
      m += a[j][r];
    }
    cout << m << endl;
  }
}
