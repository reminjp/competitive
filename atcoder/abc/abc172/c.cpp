#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(n + 1), b(m + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i + 1];
    a[i + 1] += a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i + 1];
    b[i + 1] += b[i];
  }

  int r = 0;
  for (int p = 0, q = m; p <= n; p++) {
    while (q >= 0 && a[p] + b[q] > k) q--;
    if (q < 0) break;
    r = max(r, p + q);
  }
  cout << r << endl;
}
