#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll powll(ll x, ll y) {
  ll r = 1;
  for (ll i = 0; i < y; i++) r *= x;
  return r;
}

int main() {
  ll n;
  while (cin >> n, n) {
    ll d = 1, s = 0;
    for (ll k = 0; s + k < n; k = 9 * 9 * (powll(2, d - 1) - 1)) {
      d += 1;
      s += k;
    }
    string r;
    set<int> t;
    while (d) {
      int x;
      if (t.size() == 0) {
        for (x = 1; x <= 9; x++) {
          ll k = 9 * (powll(2, d - 1) - 1);
          if (n <= s + k) {
            break;
          }
          s += k;
        }
        t.insert(x);
      } else if (t.size() == 1) {
        for (x = 0; x <= 9; x++) {
          ll k;
          if (t.count(x)) {
            k = 9 * (powll(2, d - 1) - 1);
          } else {
            k = powll(2, d - 1);
          }
          if (n <= s + k) {
            break;
          }
          s += k;
        }
        if (!t.count(x)) {
          t.insert(x);
        }
      } else {
        for (auto e : t) {
          ll k = powll(2, d - 1);
          if (n <= s + k) {
            x = e;
            break;
          }
          s += k;
        }
      }
      r.push_back('0' + x);
      d--;
    }
    cout << r << endl;
  }
}
