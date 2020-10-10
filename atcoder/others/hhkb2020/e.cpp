#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

using mint = modint1000000007;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (auto& e : s) cin >> e;

  int k = 0;
  for (const auto& e : s) {
    for (auto& e : e) {
      if (e != '#') k++;
    }
  }

  vector<mint> p(k + 1);
  p[0] = 1;
  for (int i = 1; i <= k; i++) p[i] = p[i - 1] * 2;

  vector v(h, vector(w, vector<int>(4)));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') continue;
      v[i][j][0] = (i - 1 >= 0 ? v[i - 1][j][0] : 0) + 1;
      v[i][j][1] = (j - 1 >= 0 ? v[i][j - 1][1] : 0) + 1;
    }
  }
  for (int i = h - 1; i >= 0; i--) {
    for (int j = w - 1; j >= 0; j--) {
      if (s[i][j] == '#') continue;
      v[i][j][2] = (i + 1 < h ? v[i + 1][j][2] : 0) + 1;
      v[i][j][3] = (j + 1 < w ? v[i][j + 1][3] : 0) + 1;
    }
  }

  mint r(0);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') continue;
      int t = v[i][j][0] + v[i][j][1] + v[i][j][2] + v[i][j][3] - 3;
      r += (p[t] - 1) * p[k - t];
    }
  }
  cout << r.val() << endl;
}
