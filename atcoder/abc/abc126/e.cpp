#include <bits/stdc++.h>
using namespace std;

class union_find {
 private:
  vector<int> parent;
  vector<int> rank;

 public:
  union_find(int n) : parent(n), rank(n) {
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
  }
  int find(int a) { return parent[a] == a ? a : parent[a] = find(parent[a]); }
};

int main() {
  int n, m;
  cin >> n >> m;
  union_find uf(n);
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    uf.unite(x - 1, y - 1);
  }
  set<int> s;
  for (int i = 0; i < n; i++) s.insert(uf.find(i));
  cout << s.size() << endl;
}
