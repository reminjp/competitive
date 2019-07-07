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
  T operator()(T n, T k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return factrial[n] * inverse_factrial[k] % mod * inverse_factrial[n - k] % mod;
  }
};

int main() {
  ll n, k;
  cin >> n >> k;
  vector<vector<int>> v(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    v[a - 1].push_back(b - 1);
    v[b - 1].push_back(a - 1);
  }

  ModuloCombination<ll, mod> c(k - 1);
  vector<ll> f(n);
  f[0] = 1;
  for (ll i = 1; i <= n - 1; i++) f[i] = f[i - 1] * i % mod;

  function<ll(int i, int j)> dfs = [&](int i, int j) -> ll {
    ll r;
    if (i == j) {
      r = k * (c(k - 1, v[j].size()) * f[v[j].size()] % mod);
    } else {
      r = c(k - 2, v[j].size() - 1) * f[v[j].size() - 1] % mod;
    }
    r %= mod;
    for (auto e : v[j]) {
      if (e == i) continue;
      r *= dfs(j, e);
      r %= mod;
    }
    return r;
  };

  cout << dfs(0, 0) << endl;
}
