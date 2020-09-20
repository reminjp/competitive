#include <bits/stdc++.h>
using namespace std;

#include <atcoder/dsu>
using namespace atcoder;

int main() {
  int n, q;
  cin >> n >> q;
  dsu d(n);
  while (q--) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 0) {
      d.merge(u, v);
    } else {
      cout << (int)d.same(u, v) << endl;
    }
  }
}
