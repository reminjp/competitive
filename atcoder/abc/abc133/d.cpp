#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& e : a) cin >> e;

  vector<ll> x(n);
  ll l = 0, r = 1e9 + 1, m;
  while (true) {
    m = (l + r) / 2;
    x[0] = 2 * m;
    for (int i = 0; i + 1 < n; i++) {
      x[i + 1] = 2 * (a[i] - x[i] / 2);
    }
    if (x[0] / 2 + x[n - 1] / 2 < a[n - 1]) {
      l = m + 1;
    } else if (x[0] / 2 + x[n - 1] / 2 > a[n - 1]) {
      r = m;
    } else {
      break;
    }
  }

  for (auto e : x) cout << e << ' ';
  cout << endl;
}
