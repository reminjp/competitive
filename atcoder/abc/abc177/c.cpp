#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 1e9 + 7;

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

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& e : a) cin >> e;

  ll s = 0;
  for (auto e : a) (s += e) %= MOD;

  ll r = 0;
  for (auto e : a) (r += (MOD + s - e) % MOD * e) %= MOD;
  r *= ModuloInverse(2, MOD);
  r %= MOD;
  cout << r << endl;
}
