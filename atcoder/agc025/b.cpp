#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;

class FermatCombination {
 private:
  vector<int> factrial;
  vector<int> inverse;
  int mod;

  int pow(int x, int n) {
    long long r = 1;
    while (n > 0) {
      if (n & 1) r = r * x % mod;
      x = (long long)x * x % mod;
      n >>= 1;
    }
    return r;
  }

 public:
  FermatCombination(int size, int mod) {
    this->factrial = vector<int>(size + 1);
    this->inverse = vector<int>(size + 1);
    this->mod = mod;

    factrial[0] = 1;
    inverse[0] = 1;
    for (int i = 1; i <= size; i++) {
      factrial[i] = (long long)factrial[i - 1] * i % mod;
      inverse[i] = pow(factrial[i], mod - 2);
    }
  }

  int operator()(int n, int k) {
    return (long long)factrial[n] * inverse[k] % mod * inverse[n - k] % mod;
  }
};

int main() {
  ll n, a[2], k;
  cin >> n >> a[0] >> a[1] >> k;
  sort(a, a + 2);
  FermatCombination c(n, mod);
  ll r = 0;
  for (ll i = 0; i <= n && i * a[1] <= k; i++) {
    ll j = (k - i * a[1]) / a[0];
    if (j <= n && i * a[1] + j * a[0] == k) {
      r = (r + (ll)c(n, i) * c(n, j)) % mod;
    }
  }
  cout << r << endl;
  return 0;
}
