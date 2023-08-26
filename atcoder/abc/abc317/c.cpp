#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1e18;

template <class T>
void set_if_greater(T& a, T b) {
  if (a < b) a = b;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector g(n, vector<ll>(n, INF));
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    g[a][b] = g[b][a] = c;
  }

  vector dp(1 << n, vector<ll>(n));
  for (int b = 1; b < (1 << n); b++) {
    for (int i = 0; i < n; i++) {
      if (!(b & (1 << i))) continue;
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        if (b & (1 << j)) continue;
        if (g[i][j] == INF) continue;
        set_if_greater(dp[b | 1 << j][j], dp[b][i] + g[i][j]);
      }
    }
  }

  ll r = 0;
  for (int b = 1; b < (1 << n); b++) {
    for (int i = 0; i < n; i++) {
      set_if_greater(r, dp[b][i]);
    }
  }
  cout << r << endl;
}
