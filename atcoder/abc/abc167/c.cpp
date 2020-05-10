#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9;

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> c(n);
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    for (int j = 0; j < m; j++) cin >> a[i][j];
  }

  int r = INF;
  for (int b = 0; b < (1 << n); b++) {
    int cs = 0;
    vector<int> s(m);
    for (int i = 0; i < n; i++) {
      if (!(b >> i & 1)) continue;
      cs += c[i];
      for (int j = 0; j < m; j++) s[j] += a[i][j];
    }
    if (*min_element(s.begin(), s.end()) >= x) {
      r = min(r, cs);
    }
  }
  cout << (r == INF ? -1 : r) << endl;
}
