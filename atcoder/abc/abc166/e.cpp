#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& e : a) cin >> e;
  for (ll i = 0; i < n; i++) a[i] -= i;

  map<ll, ll> m;
  for (auto e : a) m[e]++;

  ll r = 0;
  for (ll i = 0; i < n; i++) {
    r += m[-(a[i] + 2 * i)];
    m[a[i]]--;
  }
  cout << r << endl;
}
