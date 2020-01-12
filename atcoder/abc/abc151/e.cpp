#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 1e9 + 7;

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
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto& e : a) cin >> e;
  sort(a.begin(), a.end());

  ModuloCombination<ll, MOD> c(n);

  ll r = 0;
  for (int i = 0; i < n; i++) {
    r += MOD - c(n - i - 1, k - 1) * a[i] % MOD;
    r %= MOD;
    r += c(i, k - 1) * a[i];
    r %= MOD;
  }
  cout << r << endl;
}
