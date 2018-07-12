#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int E = 12;
const int M = 52;

int main() {
  ll n;
  while (cin >> n, n) {
    string s;
    cin >> s;
    ll m0 = 1ll << M;
    for (int i = 0; i < M; i++) {
      m0 |= (ll)(s[i] - '0') << (M - 1 - i);
    }

    ll e = 0, m = m0;
    for (ll i = 0, k; i < n; i += k) {
      k = m0 >> e ? ((1ll << M + 1) - m - 1) / (m0 >> e) + 1 : 1e18;
      if (i + k <= n) {
        m = m + k * (m0 >> e) >> 1;
        e++;
      } else {
        m = m + (n - i) * (m0 >> e);
      }
    }

    cout << bitset<E>(e) << bitset<M>(m) << endl;
  }
}
