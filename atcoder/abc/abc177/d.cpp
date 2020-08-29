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
  int n, m;
  cin >> n >> m;

  UnionFind uf(n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    uf.Unite(a - 1, b - 1);
  }

  int r = 0;
  for (int i = 0; i < n; i++) r = max(r, uf.Size(i));
  cout << r << endl;
}
