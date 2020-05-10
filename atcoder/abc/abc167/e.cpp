#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 998244353;

template <class T, T MOD>
class ModuloCombination {
 private:
  std::vector<T> factrial, inverse_factrial;
  T Pow(T x, T y) {
    if (y == 0) return 1;
    if (y % 2 == 0) return Pow(x * x % MOD, y / 2);
    return x * Pow(x, y - 1) % MOD;
  }

 public:
  ModuloCombination(T n) : factrial(n + 1), inverse_factrial(n + 1) {
    inverse_factrial[0] = factrial[0] = 1;
    for (T i = 1; i <= n; i++) {
      factrial[i] = factrial[i - 1] * i % MOD;
      inverse_factrial[i] = Pow(factrial[i], MOD - 2);
    }
  }
  T operator()(T n, T k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return factrial[n] * inverse_factrial[k] % MOD * inverse_factrial[n - k] % MOD;
  }
};

int main() {
  ll n, m, k;
  cin >> n >> m >> k;

  vector<ll> p(n + 1);
  p[0] = 1;
  p[1] = m;
  for (ll i = 2; i <= n; i++) p[i] = p[i - 1] * (m - 1) % MOD;

  ModuloCombination<ll, MOD> c(n - 1);

  ll r = 0;
  for (ll i = 0; i <= k; i++) {
    r += c(n - 1, i) * p[n - i] % MOD;
    r %= MOD;
  }
  cout << r << endl;
}
