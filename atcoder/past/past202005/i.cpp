#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, q;
  cin >> n >> q;

  auto f = [n](ll i, ll j) { return n * i + j; };

  bool s = false;
  vector<int> r(n), c(n);
  iota(r.begin(), r.end(), 0);
  iota(c.begin(), c.end(), 0);
  while (q--) {
    int t;
    cin >> t;
    if (t == 3) {
      s = !s;
    } else {
      int a, b;
      cin >> a >> b;
      a--, b--;
      if (t == 1) {
        if (!s) {
          swap(r[a], r[b]);
        } else {
          swap(c[a], c[b]);
        }
      } else if (t == 2) {
        if (!s) {
          swap(c[a], c[b]);
        } else {
          swap(r[a], r[b]);
        }
      } else if (t == 4) {
        cout << (!s ? f(r[a], c[b]) : f(r[b], c[a])) << endl;
      }
    }
  }
}
