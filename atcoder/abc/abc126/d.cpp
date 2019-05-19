#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> v;
vector<int> r;

void dfs(int i, int j, int d) {
  r[j] = d;
  for (auto e : v[j]) {
    if (e.first == i) continue;
    dfs(j, e.first, (d + e.second) % 2);
  }
}

int main() {
  int n;
  cin >> n;
  v = vector<vector<pair<int, int>>>(n);
  for (int i = 0; i < n - 1; i++) {
    int p, q, w;
    cin >> p >> q >> w;
    p--;
    q--;
    v[p].push_back({q, w});
    v[q].push_back({p, w});
  }
  r = vector<int>(n);
  dfs(0, 0, 0);
  for (auto e : r) cout << e << endl;
}
