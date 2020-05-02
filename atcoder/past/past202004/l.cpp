#include <bits/stdc++.h>
using namespace std;

template <class Monoid>
class SegmentTree {
 private:
  using S = typename std::vector<Monoid>::size_type;
  using F = std::function<Monoid(Monoid, Monoid)>;
  S size;
  std::vector<Monoid> nodes;
  const Monoid identity;
  const F operate;

 public:
  SegmentTree(S n, const Monoid& identity, const F& operate) : identity(identity), operate(operate) {
    size = 1;
    while (size < n) size *= 2;
    nodes.assign(2 * size, identity);
  }
  void Update(S i, const Monoid& x) {
    i += (size - 1);
    nodes[i] = x;
    while (i > 0) {
      i = (i - 1) / 2;
      nodes[i] = operate(nodes[2 * i + 1], nodes[2 * i + 2]);
    }
  }
  Monoid Query(S begin, S end, S i = 0, S b = 0, S e = 0) {
    if (e == 0) e = size;
    if (e <= begin || end <= b) return identity;
    if (begin <= b && e <= end) return nodes[i];
    return operate(Query(begin, end, 2 * i + 1, b, (b + e) / 2), Query(begin, end, 2 * i + 2, (b + e) / 2, e));
  }
};

int main() {
  int n, k, d;
  cin >> n >> k >> d;
  SegmentTree<pair<int, int>> st(n, {1e9, n}, [](pair<int, int> a, pair<int, int> b) { return std::min(a, b); });
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    st.Update(i, {a, i});
  }

  if (n < (k - 1) * d + 1) {
    cout << -1 << endl;
    return 0;
  }

  vector<int> r;
  int h = 0;
  while (r.size() < k) {
    auto e = st.Query(h, n - (k - r.size() - 1) * d);
    r.push_back(e.first);
    h = e.second + d;
  }

  for (auto e : r) cout << e << ' ';
  cout << endl;
}
