#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = (int)1e9 + 7;

int main() {
  string s;
  cin >> s;
  int n = s.size();

  vector<ll> p(n + 1);
  p[0] = 1;
  for (int i = 0; i < n; i++) {
    p[i + 1] = 3 * p[i] % mod;
  }

  vector<ll> a(n + 1), c(n + 1), q(n + 1);
  for (int i = 0; i < n; i++) {
    switch (s[i]) {
      case 'A':
        a[i + 1] = 1;
        break;
      case 'C':
        c[i + 1] = 1;
        break;
      case '?':
        q[i + 1] = 1;
        break;
    }
  }
  for (int i = 0; i < n; i++) {
    a[i + 1] += a[i];
    c[i + 1] += c[i];
    q[i + 1] += q[i];
  }

  ll r = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B' || s[i] == '?') {
      ll ra = (a[i] - a[0]) * p[q[i] - q[0]] % mod + (q[i] - q[0]) * p[max(0ll, q[i] - q[0] - 1)] % mod;
      ll rc = (c[n] - c[i + 1]) * p[q[n] - q[i + 1]] % mod + (q[n] - q[i + 1]) * p[max(0ll, q[n] - q[i + 1] - 1)] % mod;
      r = (r + ra * rc) % mod;
    }
  }
  cout << r << endl;
}
