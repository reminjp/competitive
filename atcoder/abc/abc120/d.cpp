#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class union_find {
 private:
  vector<int> parent;
  vector<int> rank;
  vector<int> sizes;

 public:
  union_find(int n) : parent(n), rank(n), sizes(n, 1) {
    for (int i = 0; i < n; i++) parent[i] = i;
  }
  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (rank[a] < rank[b]) {
      parent[a] = b;
    } else {
      parent[b] = a;
      if (rank[a] == rank[b]) rank[a]++;
    }
    sizes[find(a)] = sizes[a] + sizes[b];
  }
  int find(int a) { return parent[a] == a ? a : parent[a] = find(parent[a]); }
  int size(int a) { return sizes[find(a)]; }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(m);
  for (auto& e : a) {
    cin >> e.first >> e.second;
    e.first--;
    e.second--;
  }
  union_find uf(n);
  vector<ll> r(m);
  r[m - 1] = (ll)n * (n - 1) / 2;
  for (int i = m - 1; i >= 1; i--) {
    r[i - 1] = r[i];
    if (uf.find(a[i].first) != uf.find(a[i].second)) {
      r[i - 1] -= (ll)uf.size(a[i].first) * uf.size(a[i].second);
      uf.unite(a[i].first, a[i].second);
    }
  }
  for (auto e : r) {
    cout << e << endl;
  }
}
