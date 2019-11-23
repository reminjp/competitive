#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &e : a) cin >> e;
  for (int i = 0; i + 1 < n; i++) a[i + 1] += a[i];
  ll r = 1e18;
  for (int i = 0; i + 1 < n; i++) r = min(r, abs((a[n - 1] - a[i]) - a[i]));
  cout << r << endl;
}
