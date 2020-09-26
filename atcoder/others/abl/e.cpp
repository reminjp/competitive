#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

using ll = long long;
constexpr int MOD = 998244353;

using S = pair<ll, ll>;

using F = ll;

S op(S a, S b) { return S{(a.first + b.first) % MOD, (a.second + b.second) % MOD}; }

S e() { return {0, 0}; }

S mapping(F f, S s) { return f ? S{s.first, f * s.first % MOD} : s; }

F composition(F a, F b) { return a ? a : b; }

F id() { return 0; }

int main() {
  int n, q;
  cin >> n >> q;

  vector<S> u(n);
  u.front() = {1, 1};
  for (int i = 1; i < n; i++) u[i].first = u[i].second = u[i - 1].first * 10 % MOD;

  lazy_segtree<S, op, e, F, mapping, composition, id> seg(u);

  while (q--) {
    int l, r, d;
    cin >> l >> r >> d;
    seg.apply(n - r, n - l + 1, d);
    cout << seg.all_prod().second << endl;
  }
}
