#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 1e9 + 7;

template <typename T, T mod>
class ModuloCombination {
 private:
  std::vector<T> factrial, inverse_factrial;
  T Pow(T x, T y) {
    if (y == 0) return 1;
    if (y % 2 == 0) return Pow(x * x % mod, y / 2);
    return x * Pow(x, y - 1) % mod;
  }

 public:
  ModuloCombination(T n) : factrial(n + 1), inverse_factrial(n + 1) {
    inverse_factrial[0] = factrial[0] = 1;
    for (T i = 1; i <= n; i++) {
      factrial[i] = factrial[i - 1] * i % mod;
      inverse_factrial[i] = Pow(factrial[i], mod - 2);
    }
  }
  T operator()(T n, T k) { return factrial[n] * inverse_factrial[k] % mod * inverse_factrial[n - k] % mod; }
};

int main() {
  int n, k;
  cin >> n >> k;
  ModuloCombination<ll, mod> c(n);
  for (int i = 1; i <= k; i++) {
    cout << c(k - 1, i - 1) * (n - k + 1 >= i ? c(n - k + 1, i) : 0) % mod << endl;
  }
}
