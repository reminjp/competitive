#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 1e9 + 7;

template <class T>
T ArithmeticSeries(T a, T d, T n) {
  return n * (2 * a + (n - 1) * d) / 2;
}

int main() {
  ll n, k;
  cin >> n >> k;

  ll r = 0;
  for (ll i = k; i <= n + 1; i++) {
    ll s_min = ArithmeticSeries(0ll, 1ll, i);
    ll s_max = ArithmeticSeries(n, -1ll, i);
    r += s_max - s_min + 1;
    r %= MOD;
  }
  cout << r << endl;
}
