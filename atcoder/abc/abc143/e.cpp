#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9 + 1;

int main() {
  int n, m, l;
  cin >> n >> m >> l;
  vector<vector<int>> d(n, vector<int>(n, INF)), r(n, vector<int>(n, INF));
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    d[a][b] = c;
    d[b][a] = c;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (d[i][j] <= l) r[i][j] = 1;
    }
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (r[i][k] + r[k][j] < r[i][j]) r[i][j] = r[i][k] + r[k][j];
      }
    }
  }

  int q;
  cin >> q;
  for (; q > 0; q--) {
    int s, t;
    cin >> s >> t;
    s--, t--;
    cout << (r[s][t] != INF ? r[s][t] - 1 : -1) << endl;
  }
}
