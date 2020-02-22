#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

template <class T>
T ModuloInverse(T a, T m) {
  T b = m, x = 1, y = 0;
  while (b) {
    T t = a / b;
    a -= t * b;
    x -= t * y;
    std::swap(a, b);
    std::swap(x, y);
  }
  return (m + x % m) % m;
}

ll c(ll n, ll k) {
  ll a = 1, b = 1;
  for (ll i = 0; i < k; i++) {
    a = a * (n - i) % MOD;
    b = b * (i + 1) % MOD;
  }
  return a * ModuloInverse(b, MOD) % MOD;
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  ll p = 1;
  for (int i = 0; i < n; i += 32) p = (p << min(32, n - i)) % MOD;
  p = (MOD + p - c(n, a)) % MOD;
  p = (MOD + p - c(n, b)) % MOD;
  p = (MOD + p - 1) % MOD;
  cout << p << endl;
}
