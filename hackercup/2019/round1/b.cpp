#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 1e9 + 7;

int p[(int)1e6 + 1];

void initialize() {
  p[0] = 1;
  for (int i = 1; i <= (int)1e6; i++) p[i] = p[i - 1] * 2 % mod;
}

void solve() {
  int n, k;
  string v;
  cin >> n >> k >> v;
  reverse(begin(v), end(v));
  ll m = 0, d = 0;
  for (int l = 0, r = 1; r <= n; r++) {
    if (v[r - 1] == 'A') d--;
    if (v[r - 1] == 'B') d++;
    if (d > k) {
      v[r - 1] = 'A';
      d -= 2;
      m += p[n - r + 1];
      m %= mod;
    }
    if (d <= 0) {
      l = r;
      d = 0;
    }
  }
  cout << m << endl;
}

int main() {
  initialize();
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
