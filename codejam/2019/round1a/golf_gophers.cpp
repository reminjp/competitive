#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline long long mod(long long a, long long m) { return (a % m + m) % m; }

long long extended_gcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = extended_gcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

long long modulo_inverse(long long a, long long m) {
  long long x, y;
  extended_gcd(a, m, x, y);
  return mod(x, m);
}

long long garner(const vector<long long> &a, vector<long long> m, long long M) {
  m.push_back(M);
  vector<long long> coeffs((int)m.size(), 1);
  vector<long long> constants((int)m.size(), 0);
  for (int k = 0; k < (int)a.size(); ++k) {
    long long t = mod((a[k] - constants[k]) * modulo_inverse(coeffs[k], m[k]), m[k]);
    for (int i = k + 1; i < (int)m.size(); ++i) {
      (constants[i] += t * coeffs[i]) %= m[i];
      (coeffs[i] *= m[k]) %= m[i];
    }
  }
  return constants.back();
}

vector<ll> primes = {4, 3, 5, 7, 11, 13, 17};

void solve(int n, int m) {
  vector<ll> a(primes.size());
  assert(n >= primes.size());
  for (int i = 0; i < primes.size(); i++) {
    for (int j = 0; j < 18; j++) cout << primes[i] << " ";
    cout << endl;
    for (int j = 0; j < 18; j++) {
      int e;
      cin >> e;
      a[i] += e;
    }
    a[i] %= primes[i];
  }
  cout << garner(a, primes, 1e9 + 7) << endl;
  int verdict;
  cin >> verdict;
  if (verdict == -1) exit(0);
}

int main() {
  int t, n, m;
  cin >> t >> n >> m;
  for (; t > 0; t--) solve(n, m);
}
