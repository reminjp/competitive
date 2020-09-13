#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;

  ll r8 = 1, r9 = 1, r10 = 1;
  for (int i = 0; i < n; i++) {
    (r8 *= 8) %= MOD;
    (r9 *= 9) %= MOD;
    (r10 *= 10) %= MOD;
  }
  cout << (r10 + 2 * (MOD - r9) + r8) % MOD << endl;
}
