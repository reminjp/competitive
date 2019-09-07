#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    ll p;
    cin >> p;
    a[p - 1] = i;
  }
  ll s = 0;
  vector<ll> l(n, -1), r(n, -1);
  for (ll p = 1; p <= n; p++) {
    ll i = a[p - 1];
    l[i] = 0 <= i - 1 && l[i - 1] != -1 ? l[i - 1] : i;
    r[i] = i + 1 < n && r[i + 1] != -1 ? r[i + 1] : i;
    r[l[i]] = r[i];
    l[r[i]] = l[i];
    ll t = s;
    if (l[i] - 1 >= 0) {
      s += p * (abs(r[i] - i) + 1) * (l[i] - 2 >= 0 && l[l[i] - 2] != -1 ? abs(l[l[i] - 2] - l[i]) : 1);
    }
    if (r[i] + 1 < n) {
      s += p * (abs(l[i] - i) + 1) * (r[i] + 2 < n && r[r[i] + 2] != -1 ? abs(r[r[i] + 2] - r[i]) : 1);
    }
  }
  cout << s << endl;
}
