#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class UnionFind {
 private:
  std::vector<int> parent;
  std::vector<int> rank;
  std::vector<int> sizes;

 public:
  UnionFind(int n) : parent(n), rank(n), sizes(n, 1) {
    for (int i = 0; i < n; i++) parent[i] = i;
  }
  void Unite(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    if (rank[a] < rank[b]) {
      parent[a] = b;
    } else {
      parent[b] = a;
      if (rank[a] == rank[b]) rank[a]++;
    }
    sizes[Find(a)] = sizes[a] + sizes[b];
  }
  int Find(int a) { return parent[a] == a ? a : parent[a] = Find(parent[a]); }
  int Size(int a) { return sizes[Find(a)]; }
};

int main() {
  int n;
  cin >> n;
  vector<set<int>> xys(1e5 + 1), yxs(1e5 + 1);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    xys[x].insert(y);
    yxs[y].insert(x);
  }

  UnionFind uf(1e5 + 1);
  for (auto s : yxs) {
    for (auto e : s) {
      uf.Unite(*begin(s), e);
    }
  }

  ll r = 0;
  for (int i = 0; i < xys.size(); i++) {
    int f = uf.Find(i);
    if (i == f) continue;
    for (auto e : xys[i]) {
      if (xys[f].count(e)) continue;
      xys[f].insert(e);
      r++;
    }
  }
  for (int i = 0; i < xys.size(); i++) {
    int f = uf.Find(i);
    if (i == f) continue;
    r += (ll)xys[f].size() - xys[i].size();
  }
  cout << r << endl;
}
