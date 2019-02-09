#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<vector<int>> c;
vector<int> d, m;

int dfs1(int i) {
  int r = 1;
  for (auto e : c[i]) {
    d[e] = d[i] + 1;
    r += dfs1(e);
  }
  return m[i] = r;
}

vector<ll> r;

void dfs2(int i) {
  for (auto e : c[i]) {
    r[e] = r[i] - m[e] + (n - m[e]);
    dfs2(e);
  }
}

int main() {
  cin >> n;
  c = vector<vector<int>>(n);
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    c[p].push_back(i);
  }

  d = vector<int>(n);
  m = vector<int>(n);
  dfs1(0);

  r = vector<ll>(n);
  for (auto e : d) {
    r[0] += e;
  }
  dfs2(0);

  for (auto e : r) {
    cout << e << endl;
  }
}
