#include <bits/stdc++.h>
using namespace std;

class UnionFind {
 private:
  std::vector<size_t> parents;
  std::vector<size_t> ranks;
  std::vector<size_t> sizes;

 public:
  UnionFind(size_t n) : parents(n), ranks(n), sizes(n, 1) {
    for (size_t i = 0; i < n; i++) parents[i] = i;
  }
  void Unite(size_t a, size_t b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    if (ranks[a] < ranks[b]) {
      parents[a] = b;
    } else {
      parents[b] = a;
      if (ranks[a] == ranks[b]) ranks[a]++;
    }
    sizes[Find(a)] = sizes[a] + sizes[b];
  }
  int Find(size_t a) { return parents[a] == a ? a : parents[a] = Find(parents[a]); }
  int Size(size_t a) { return sizes[Find(a)]; }
};

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> r(n);
  UnionFind uf(n);
  while (m--) {
    int p, q;
    cin >> p >> q;
    p--, q--;
    uf.Unite(p, q);
    r[p]--, r[q]--;
  }
  for (int i = 0; i < n; i++) r[i] += uf.Size(i) - 1;
  while (k--) {
    int p, q;
    cin >> p >> q;
    p--, q--;
    if (uf.Find(p) == uf.Find(q)) r[p]--, r[q]--;
  }

  for (auto e : r) cout << e << ' ';
  cout << endl;
}
