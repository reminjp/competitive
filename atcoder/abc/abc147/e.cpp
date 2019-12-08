#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w)), b(h, vector<int>(w));
  for (auto& v : a) {
    for (auto& e : v) cin >> e;
  }
  for (auto& v : b) {
    for (auto& e : v) cin >> e;
  }

  constexpr int S = 80 * 80;
  vector<vector<bitset<2 * S + 1>>> s(h + 1, vector<bitset<2 * S + 1>>(w + 1));
  s[0][0].set(S);
  s[0][1].set(S);
  s[1][0].set(S);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int d = abs(a[i][j] - b[i][j]);
      s[i + 1][j + 1] |= s[i][j + 1] << d;
      s[i + 1][j + 1] |= s[i][j + 1] >> d;
      s[i + 1][j + 1] |= s[i + 1][j] << d;
      s[i + 1][j + 1] |= s[i + 1][j] >> d;
    }
  }
  string ss = (s[h][w] >> S).to_string();
  cout << find(ss.rbegin(), ss.rend(), '1') - ss.rbegin() << endl;
}
