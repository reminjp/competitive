#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int m;
  cin >> m;
  vector<ll> d(m), c(m);
  for (int i = 0; i < m; i++) cin >> d[i] >> c[i];
  ll r = 0;
  vector<ll> a;
  for (int i = 0; i < m; i++) {
    while (c[i] >= 2) {
      if (c[i] % 2 != 0) {
        a.push_back(d[i]);
        c[i]--;
      }
      if (d[i] < 5) {
        r += c[i] / 2;
        d[i] = d[i] * 2;
      } else {
        r += c[i];
        d[i] = (d[i] * 2) % 10 + 1;
      }
      c[i] /= 2;
    }
    a.push_back(d[i]);
  }
  while (a.size() >= 2) {
    r++;
    ll e1 = a[a.size() - 2], e2 = a[a.size() - 1];
    if (e1 + e2 < 10) {
      a.pop_back();
      a[a.size() - 1] = e1 + e2;
    } else {
      a[a.size() - 2] = 1;
      a[a.size() - 1] = (e1 + e2) % 10;
    }
  }
  cout << r << endl;
}
