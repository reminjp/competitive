#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, s, t;
  cin >> n >> m;
  vector<vector<int>> v(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v[a - 1].push_back(b - 1);
  }
  cin >> s >> t;
  s--;
  t--;

  vector<vector<int>> d(n, vector<int>(3, 1e9));
  queue<pair<int, int>> q;
  d[s][0] = 0;
  q.push({s, 0});
  while (!q.empty()) {
    auto e = q.front();
    int i = e.first, di = e.second;
    q.pop();
    for (auto j : v[i]) {
      if (di + 1 < d[j][(di + 1) % 3]) {
        d[j][(di + 1) % 3] = di + 1;
        q.push({j, di + 1});
      }
    }
  }

  cout << (d[t][0] != int(1e9) ? d[t][0] / 3 : -1) << endl;
}
