#include <bits/stdc++.h>
using namespace std;

template <class T>
std::vector<T> Dijkstra(const std::vector<std::vector<std::pair<int, T>>>& graph, int s) {
  std::vector<T> dist(graph.size(), std::numeric_limits<T>::max());
  std::priority_queue<std::pair<T, int>> q;
  q.push(std::pair<T, int>{0, s});
  while (!q.empty()) {
    int i = q.top().second;
    T di = -q.top().first;
    q.pop();
    if (dist[i] <= di) continue;
    dist[i] = di;
    for (auto e : graph[i]) {
      int j = e.first;
      T dj = di + e.second;
      if (dist[j] > dj) q.push(std::pair<T, int>{-dj, j});
    }
  }
  return dist;
}

int main() {
  int n, m, s, k;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  while (m--) {
    int i, j;
    cin >> i >> j;
    i--, j--;
    g[i].push_back({j, 1});
    g[j].push_back({i, 1});
  }
  cin >> s >> k;
  s--;
  vector<int> t(k);
  for (auto& e : t) {
    cin >> e;
    e--;
  }

  vector<vector<int>> a(k + 1, vector<int>(k + 1));
  t.push_back(s);
  for (int i = 0; i < k + 1; i++) {
    auto d = Dijkstra(g, t[i]);
    for (int j = 0; j < k + 1; j++) a[i][j] = d[t[j]];
  }

  // for (int i = 0; i < k + 1; i++) {
  //   for (int j = 0; j < k + 1; j++) cerr << a[i][j] << ' ';
  //   cerr << endl;
  // }

  vector<vector<int>> dp(k, vector<int>(1 << k, 1e9));
  for (int i = 0; i < k; i++) dp[i][1 << i] = a[k][i];
  for (int b = 0; b < (1 << k); b++) {
    for (int i = 0; i < k; i++) {
      if (!(b >> i & 1)) continue;
      for (int j = 0; j < k; j++) {
        if (b >> j & 1) continue;
        int b2 = b | 1 << j;
        dp[j][b2] = min(dp[j][b2], dp[i][b] + a[i][j]);
      }
    }
  }

  int r = 1e9;
  for (int i = 0; i < k; i++) r = min(r, dp[i][(1 << k) - 1]);
  cout << r << endl;
}
