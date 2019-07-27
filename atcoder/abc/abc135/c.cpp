#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n + 1), b(n);
  for (auto& e : a) cin >> e;
  for (auto& e : b) cin >> e;
  b.push_back(0);
  ll r = 0;
  for (ll i = 0, t = 0; i < n + 1; i++) {
    ll m = min(t + b[i], a[i]);
    r += m;
    t = min(t + b[i] - m, b[i]);
  }
  cout << r << endl;
}
