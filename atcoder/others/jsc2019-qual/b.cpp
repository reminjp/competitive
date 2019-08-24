#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 1e9 + 7;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<int> a(n), s;
  for (auto &e : a) cin >> e;
  s = a;
  sort(begin(s), end(s));

  ll r = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      r += k * int(a[j] > a[i]) % mod;
      r %= mod;
    }
    ll p = n - (upper_bound(begin(s), end(s), a[i]) - begin(s));
    r += k * (k - 1) / 2 % mod * p % mod;
    r %= mod;
  }
  cout << r << endl;
}
