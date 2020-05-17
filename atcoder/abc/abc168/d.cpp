#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> r(n, -1);
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    auto i = q.front();
    q.pop();
    for (auto j : g[i]) {
      if (r[j] == -1) {
        r[j] = i;
        q.push(j);
      }
    }
  }

  cout << "Yes" << endl;
  for (int i = 1; i < n; i++) cout << r[i] + 1 << endl;
}
