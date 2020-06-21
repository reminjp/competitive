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
  int k;
  string s;
  cin >> k >> s;
  int n = s.size();

  vector<ll> p25(k + n + 1), p26(k + n + 1);
  p25[0] = p26[0] = 1;
  for (int i = 1; i < p25.size(); i++) {
    p25[i] = p25[i - 1] * 25 % MOD;
    p26[i] = p26[i - 1] * 26 % MOD;
  }

  ModuloCombination<ll, MOD> c(k + n);

  ll r = 0;
  for (int i = n; i <= n + k; i++) {
    r += c(i - 1, n - 1) * p25[i - n] % MOD * p26[n + k - i] % MOD;
    r %= MOD;
  }
  cout << r << endl;
}
