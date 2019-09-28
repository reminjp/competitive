#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v[a - 1].push_back(b - 1);
  }

  vector<int> d(n), in(n), s, r;
  function<void(int)> dfs = [&](int i) {
    d[i] = s.size();
    s.push_back(i);
    for (auto j : v[i]) in[j]++;

    priority_queue<pair<int, int>> q;
    for (auto j : v[i]) {
      if (d[j] != -1) q.push(make_pair(d[j], j));
    }
    if (!q.empty()) {
      r = vector<int>(s.begin() + q.top().first, s.end());
      return;
    }
    for (auto j : v[i]) {
      if (d[j] != -1 || in[j] > 1) continue;
      dfs(j);
      if (!r.empty()) return;
    }

    for (auto j : v[i]) in[j]--;
    s.pop_back();
    d[i] = -1;
  };
  for (int i = 0; i < n; i++) {
    fill(d.begin(), d.end(), -1);
    fill(in.begin(), in.end(), 0);
    dfs(i);
    if (!r.empty()) break;
  }

  cout << (r.empty() ? -1 : (int)r.size()) << endl;
  for (auto e : r) cout << e + 1 << endl;
}
