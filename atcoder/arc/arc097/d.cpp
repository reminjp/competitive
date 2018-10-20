#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  for (auto &e : p) {
    cin >> e;
    e--;
  }
  vector<vector<int>> graph(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  vector<set<int>> a(n), b(n);
  vector<bool> used(n);
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      used[i] = true;
      queue<int> q;
      q.push(i);
      a[i].insert(i);
      b[i].insert(p[i]);
      while (!q.empty()) {
        int f = q.front();
        q.pop();
        for (auto e : graph[f]) {
          if (!used[e]) {
            used[e] = true;
            q.push(e);
            a[i].insert(e);
            b[i].insert(p[e]);
          }
        }
      }
    }
  }
  int r = 0;
  for (int i = 0; i < n; i++) {
    for (auto e : a[i]) {
      r += b[i].count(e);
    }
  }
  cout << r << endl;
  return 0;
}
