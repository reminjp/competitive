#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = (int)1e9 + 7;

int main() {
  int n, k;
  cin >> n >> k;

  vector<ll> p((n - k) * (n - k + 1) / 2 + 1);
  p[0] = 1;
  for (int i = 1; i < p.size(); i++) {
    p[i] = 2 * p[i - 1] % mod;
  }

  vector<ll> r(n + 1);
  for (int i = 1; i <= n; i++) {
    vector<ll> v(i);
    v[0] = p[max(0, i - 1 - k) * (max(0, i - 1 - k) + 1) / 2];
    for (int j = k + 1; j < i; j++) {
      v[j] = r[j] * p[max(0, i - 1 - j - k) * (max(0, i - 1 - j - k) + 1) / 2];
    }
    r[i] = p[max(0, i - k) * (max(0, i - k) + 1) / 2];
    for (auto e : v) {
      r[i] = (mod + r[i] - e) % mod;
    }
  }
  cout << r[n] << endl;
}
