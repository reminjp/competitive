#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = (int)1e9 + 7;

class modulo_combination {
 private:
  vector<int> factrial, inverse;
  int pow(int x, int y) {
    if (y == 0) return 1;
    if (y % 2 == 0) return pow((long long)x * x % mod, y / 2);
    return (long long)x * pow(x, y - 1) % mod;
  }

 public:
  modulo_combination(int n) : factrial(n + 1), inverse(n + 1) {
    inverse[0] = factrial[0] = 1;
    for (int i = 1; i <= n; i++) {
      factrial[i] = (long long)factrial[i - 1] * i % mod;
      inverse[i] = pow(factrial[i], mod - 2);
    }
  }
  int operator()(int n, int k) { return (long long)factrial[n] * inverse[k] % mod * inverse[n - k] % mod; }
  int f(int n) { return factrial[n]; }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (auto &e : a) cin >> e;
  for (auto &e : b) cin >> e;
  sort(begin(a), end(a));
  sort(begin(b), end(b));

  if (unique(begin(a), end(a)) != end(a) || unique(begin(b), end(b)) != end(b)) {
    cout << 0 << endl;
    return 0;
  }

  modulo_combination c(n * m + 1);

  ll r = 1;
  int p = 0;
  for (int i = 0, j = 0; i < n || j < m;) {
    ll cn, ck, fn;
    p++;
    if (i < n && j < m && a[i] == b[j]) {
      cn = a[i] - p;
      ck = (n - i - 1) + (m - j - 1);
      fn = ck;
      i++;
      j++;
    } else if (!(j < m) || i < n && a[i] < b[j]) {
      cn = a[i] - p;
      ck = m - j - 1;
      fn = ck + 1;
      i++;
    } else {
      cn = b[j] - p;
      ck = n - i - 1;
      fn = ck + 1;
      j++;
    }
    if (cn - ck < 0) {
      r = 0;
      break;
    }
    r *= (ll)c(cn, ck) * c.f(fn) % mod;
    r %= mod;
    p += ck;
  }
  cout << r << endl;
}
