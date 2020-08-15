#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T>
inline vector<T> vec(size_t n, T a) {
  return vector<T>(n, a);
}

template <class T>
void set_if_greater(T& a, T b) {
  if (a < b) a = b;
}

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  auto m = vec(h + 1, vec(w + 1, 0ll));
  while (k--) {
    ll y, x, e;
    cin >> y >> x >> e;
    m[y][x] = e;
  }

  constexpr int M = 3;
  auto dp = vec(h + 1, vec(w + 1, vec(M + 1, 0ll)));
  for (int y = 1; y <= h; y++) {
    for (int x = 1; x <= w; x++) {
      for (int i = 0; i <= M; i++) {
        set_if_greater(dp[y][x][0], dp[y - 1][x][i]);
        set_if_greater(dp[y][x][i], dp[y][x - 1][i]);
        set_if_greater(dp[y][x][1], dp[y - 1][x][i] + m[y][x]);
        if (i < M) set_if_greater(dp[y][x][i + 1], dp[y][x - 1][i] + m[y][x]);
      }
    }
  }
  cout << *max_element(dp[h][w].begin(), dp[h][w].end()) << endl;
}
