#include <bits/stdc++.h>
using namespace std;

template <class T>
inline vector<T> vec(size_t n, T a) {
  return vector<T>(n, a);
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (auto& e : s) cin >> e;

  auto dp = vec(h, vec(w, vec(2, (int)1e9)));
  dp[0][0][s[0][0] == '#'] = s[0][0] == '#';

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int k = s[i][j] == '#';
      if (i - 1 >= 0) dp[i][j][k] = min({dp[i][j][k], dp[i - 1][j][0] + k, dp[i - 1][j][1]});
      if (j - 1 >= 0) dp[i][j][k] = min({dp[i][j][k], dp[i][j - 1][0] + k, dp[i][j - 1][1]});
    }
  }

  cout << min(dp[h - 1][w - 1][0], dp[h - 1][w - 1][1]) << endl;
}
