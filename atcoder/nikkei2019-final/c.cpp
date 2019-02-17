#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<vector<ll>> s = {vector<ll>(h + 2, w), vector<ll>(w + 2, h)}, t(s.size());
  for (auto& e : s) {
    *begin(e) = *rbegin(e) = 0;
  }
  for (int i = 0; i < k; i++) {
    int r, c;
    cin >> r >> c;
    s[0][r] -= 1;
    s[1][c] -= 1;
  }
  vector<ll> r(2, 1e18);
  for (int i = 0; i < 2; i++) {
    t[i] = s[i];
    int n = (int)s[i].size() - 2;
    for (int _ = 2; _ > 0; _--) {
      for (int j = 1; j <= n; j++) {
        s[i][j + 1] += s[i][j];
        t[i][n - j + 1] += t[i][n - j + 2];
      }
    }
    for (int j = 1; j <= n; j++) {
      r[i] = min(r[i], s[i][j - 1] + t[i][j + 1]);
    }
  }
  cout << r[0] + r[1] << endl;
}
