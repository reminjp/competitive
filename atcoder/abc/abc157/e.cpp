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
  int n, q;
  string s;
  cin >> n >> s >> q;

  SegmentTree<int> st(n, 0, [](int a, int b) { return a | b; });
  for (int i = 0; i < n; i++) st.Update(i, 1 << (s[i] - 'a'));

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int i;
      char c;
      cin >> i >> c;
      st.Update(i - 1, 1 << (c - 'a'));
    } else if (t == 2) {
      int l, r;
      cin >> l >> r;
      cout << bitset<26>(st.Query(l - 1, r)).count() << endl;
    }
  }
}
