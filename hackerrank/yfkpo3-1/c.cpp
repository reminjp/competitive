#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

template <class T>
T ModuloInverse(T a, T m) {
  T b = m, x = 1, y = 0;
  while (b) {
    T t = a / b;
    a -= t * b;
    x -= t * y;
    std::swap(a, b);
    std::swap(x, y);
  }
  return (m + x % m) % m;
}

// https://ei1333.github.io/luzhiled/snippets/graph/template.html
template <typename T>
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template <typename T>
using Edges = vector<edge<T>>;
template <typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template <typename T>
using Matrix = vector<vector<T>>;

// https://ei1333.github.io/luzhiled/snippets/tree/doubling-lowest-common-ancestor.html
template <typename G>
struct DoublingLowestCommonAncestor {
  const int LOG;
  vector<int> dep;
  const G &g;
  vector<vector<int>> table;

  DoublingLowestCommonAncestor(const G &g) : g(g), dep(g.size()), LOG(32 - __builtin_clz(g.size())) {
    table.assign(LOG, vector<int>(g.size(), -1));
  }

  void dfs(int idx, int par, int d) {
    table[0][idx] = par;
    dep[idx] = d;
    for (auto &to : g[idx]) {
      if (to != par) dfs(to, idx, d + 1);
    }
  }

  void build() {
    dfs(0, -1, 0);
    for (int k = 0; k + 1 < LOG; k++) {
      for (int i = 0; i < table[k].size(); i++) {
        if (table[k][i] == -1)
          table[k + 1][i] = -1;
        else
          table[k + 1][i] = table[k][table[k][i]];
      }
    }
  }

  int query(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; i--) {
      if (((dep[v] - dep[u]) >> i) & 1) v = table[i][v];
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) {
      if (table[i][u] != table[i][v]) {
        u = table[i][u];
        v = table[i][v];
      }
    }
    return table[0][u];
  }
};

int main() {
  int n;
  cin >> n;
  vector<vector<pair<int, ll>>> v(n);
  UnWeightedGraph g(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    v[a].push_back({b, c});
    v[b].push_back({a, c});
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<ll> s(n);
  s[0] = 1;
  auto dfs = [&](auto &&dfs, int i, int j) -> void {
    for (auto e : v[j]) {
      if (e.first == i) continue;
      s[e.first] = s[j] * e.second % MOD;
      dfs(dfs, j, e.first);
    }
  };
  dfs(dfs, 0, 0);

  DoublingLowestCommonAncestor<UnWeightedGraph> lca(g);
  lca.build();
  int q;
  cin >> q;
  while (q--) {
    int a, b, x;
    cin >> a >> b >> x;
    a--, b--;
    ll r = x;
    r *= s[a];
    r %= MOD;
    r *= s[b];
    r %= MOD;
    int k = ModuloInverse(s[lca.query(a, b)], MOD);
    r *= k;
    r %= MOD;
    r *= k;
    r %= MOD;
    cout << r << endl;
  }
}
