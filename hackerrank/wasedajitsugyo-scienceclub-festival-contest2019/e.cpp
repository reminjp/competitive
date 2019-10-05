#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i + 1];
    a[i + 1] += a[i];
  }
  ll r = 1e18;
  for (int t = 1; t <= n; t++) {
    array<ll, 3> p;
    p[2] = a[n] - a[t];
    int st = lower_bound(a.begin(), a.end(), (a[t] + 1) / 2) - a.begin();
    for (int s = st - 1; s <= st; s++) {
      if (1 <= s && s <= t) {
        p[0] = a[s] - a[0];
        p[1] = a[t] - a[s];
        auto m = minmax_element(p.begin(), p.end());
        r = min(r, *m.second - *m.first);
      }
    }
  }
  cout << r << endl;
}
