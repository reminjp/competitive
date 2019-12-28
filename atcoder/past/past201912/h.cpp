#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, q;
  cin >> n;
  vector<ll> c(n + 1);
  ll min_odd = 1e9, min_all = 1e9;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    if (i % 2) min_odd = min(min_odd, c[i]);
    min_all = min(min_all, c[i]);
  }

  cin >> q;
  ll r = 0, offset_odd = 0, offset_all = 0;
  for (; q > 0; q--) {
    int s, x, a;
    cin >> s;

    if (s == 1) {
      cin >> x >> a;
      if (offset_all + x % 2 * offset_odd + a <= c[x]) {
        c[x] -= a;
        r += a;
        if (x % 2) min_odd = min(min_odd, c[x]);
        min_all = min(min_all, c[x]);
      }
    } else if (s == 2) {
      cin >> a;
      if (offset_all + offset_odd + a <= min_odd) {
        offset_odd += a;
        r += a * ((n + 1) / 2);
      }
    } else if (s == 3) {
      cin >> a;
      if (offset_all + a <= min_all && offset_all + offset_odd + a <= min_odd) {
        offset_all += a;
        r += a * n;
      }
    }
  }
  cout << r << endl;
}
