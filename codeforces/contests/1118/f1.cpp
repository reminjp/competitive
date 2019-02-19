#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<vector<int>> v;
vector<vector<int>> c, p;

void dfs1(int i, int j) {
  c[j][a[j]]++;
  for (auto e : v[j]) {
    if (e == i) continue;
    dfs1(j, e);
    for (int l = 0; l < 3; l++) c[j][l] += c[e][l];
  }
}

int dfs2(int i, int j) {
  int r = 0;
  vector<int> t = p[j];
  for (int l = 0; l < 3; l++) t[l] += c[j][l];
  for (auto e : v[j]) {
    if (e == i) continue;
    for (int l = 0; l < 3; l++) p[e][l] = t[l] - c[e][l];
    bool b = !(p[e][1] && p[e][2] || c[e][1] && c[e][2]);
    // if (b) cerr << j + 1 << " " << e + 1 << endl;
    r += b + dfs2(j, e);
  }
  return r;
}

int main() {
  int n;
  cin >> n;
  a = vector<int>(n);
  for (auto& e : a) {
    cin >> e;
  }
  v = vector<vector<int>>(n);
  c = p = vector<vector<int>>(n, vector<int>(3));
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs1(0, 0);
  cout << dfs2(0, 0) << endl;
}
