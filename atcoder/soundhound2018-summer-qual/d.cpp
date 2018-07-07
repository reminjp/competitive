#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> dijkstra(const vector<vector<pair<int, ll>>> &graph, int s) {
  vector<ll> dist(graph.size(), 1e18);
  priority_queue<pair<ll, int>> q;
  q.push(pair<ll, int>{0, s});
  while (!q.empty()) {
    int i = q.top().second;
    ll di = -q.top().first;
    q.pop();
    if (dist[i] <= di) continue;
    dist[i] = di;
    for (auto e : graph[i]) {
      int j = e.first;
      ll dj = di + e.second;
      if (dist[j] > dj) q.push(pair<ll, int>{-dj, j});
    }
  }
  return dist;
}

int main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  s--;
  t--;
  vector<vector<pair<int, ll>>> a(n), b(n);
  for (int i = 0; i < m; i++) {
    int u, v, ai, bi;
    cin >> u >> v >> ai >> bi;
    u--;
    v--;
    a[u].push_back({v, ai});
    a[v].push_back({u, ai});
    b[u].push_back({v, bi});
    b[v].push_back({u, bi});
  }
  vector<ll> c = dijkstra(a, s), d = dijkstra(b, t);
  vector<ll> r(n);
  for (int i = 0; i < n; i++) {
    r[i] = c[i] + d[i];
  }
  for (int i = n - 2; i >= 0; i--) {
    r[i] = min(r[i], r[i + 1]);
  }
  for (auto e : r) {
    cout << (ll)1e15 - e << endl;
  }
}
