#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> v(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    v[a - 1].push_back(b - 1);
    v[b - 1].push_back(a - 1);
  }
  vector<int> c(n);
  for (auto& e : c) cin >> e;
  sort(begin(c), end(c));

  int s = -c.back();
  for (auto e : c) s += e;

  vector<int> r(n, -1);
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    r[i] = c.back();
    c.pop_back();
    for (auto e : v[i]) {
      if (r[e] != -1) continue;
      q.push(e);
    }
  }

  cout << s << endl;
  for (auto e : r) cout << e << " ";
  cout << endl;
}
