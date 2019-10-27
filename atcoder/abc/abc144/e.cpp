#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), f(n);
  for (auto& e : a) cin >> e;
  for (auto& e : f) cin >> e;
  sort(a.begin(), a.end());
  sort(f.rbegin(), f.rend());

  ll bot = -1, top = 1e18, mid;
  while (bot + 1 < top) {
    mid = bot + (top - bot) / 2;
    bool b = true;
    ll t = k;
    for (int i = 0; i < n; i++) {
      if (a[i] * f[i] <= mid) continue;
      ll ax = mid / f[i];
      ll ad = a[i] - ax;
      if (ad > t) {
        b = false;
        break;
      }
      t -= ad;
    }
    if (b) {
      top = mid;
    } else {
      bot = mid;
    }
  }
  cout << top << endl;
}
