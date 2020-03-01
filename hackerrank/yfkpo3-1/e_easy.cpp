#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> as(n), b(n), c(n), ds(n);
  for (auto &e : as) cin >> e;
  for (auto &e : b) cin >> e;
  for (auto &e : c) cin >> e;
  for (auto &e : ds) cin >> e;
  for (int i = 0; i + 1 < n; i++) as[i + 1] += as[i];
  for (int i = n - 1; i - 1 >= 0; i--) ds[i - 1] += ds[i];

  vector<ll> l(n), r(n);
  l[0] = as[0];
  r[n - 1] = ds[n - 1];
  for (int i = 1; i < n; i++) l[i] = max(l[i - 1], as[i - 1]) + b[i];
  for (int i = n - 2; i >= 0; i--) r[i] = max(r[i + 1], ds[i + 1]) + c[i];

  ll m = 0;
  for (int i = 1; i < n - 2; i++) m = max(m, l[i] + r[i + 1]);
  cout << m << endl;
}
