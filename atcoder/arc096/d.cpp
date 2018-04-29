#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll n, c;
  cin >> n >> c;
  vector<ll> x(n + 2), v(n + 2);
  for (int i = 0; i < n; i++) {
    cin >> x[i + 1] >> v[i + 1];
  }
  x[n + 1] = c;
  vector<ll> a(n + 2), b(n + 2);
  for (int i = 0; i < n; i++) {
    a[i + 1] = a[i] + v[i + 1] - (x[i + 1] - x[i]);
    b[n - i] = b[n - i + 1] + v[n - i] - (x[n - i + 1] - x[n - i]);
  }
  for (int i = 0; i < n + 1; i++) {
    a[i + 1] = max(a[i], a[i + 1]);
    b[n - i] = max(b[n - i + 1], b[n - i]);
  }
  ll m = max(a.back(), b.front());
  for (int i = 0; i < n + 1; i++) {
    m = max(m, a[i] + b[i + 1] - x[i]);
    m = max(m, b[n - i + 1] + a[n - i] - (c - x[n - i + 1]));
  }
  cout << m << endl;
  return 0;
}
