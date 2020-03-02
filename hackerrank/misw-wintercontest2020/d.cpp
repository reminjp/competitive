#include <bits/stdc++.h>
using namespace std;

template <class T>
inline vector<T> vec(size_t n, T a) {
  return vector<T>(n, a);
}

template <class T>
void set_if_greater(T& a, T b) {
  if (a < b) a = b;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  for (auto& v : a) {
    for (auto& e : v) cin >> e;
  }

  constexpr int M = 3;
  auto dp = vec(h, vec(w, vec(M, vec(M, -1))));
  dp[0][0][0][0] = a[0][0];
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
          if (dp[y][x][i][j] == -1) continue;
          if (y + 1 < h && i + 1 < M) set_if_greater(dp[y + 1][x][i + 1][0], dp[y][x][i][j] + a[y + 1][x]);
          if (x + 1 < w && j + 1 < M) set_if_greater(dp[y][x + 1][0][j + 1], dp[y][x][i][j] + a[y][x + 1]);
        }
      }
    }
  }
  int r = -1;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) r = max(r, dp[h - 1][w - 1][i][j]);
  }
  cout << r << endl;
}
