#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& e : a) cin >> e;

  ll r = 0;
  for (int i = 0; i <= 60; i++) {
    int c = 0;
    for (auto e : a) c += (e >> i) & 1ll;
    r += (1ll << i) % MOD * c % MOD * (n - c) % MOD;
    r %= MOD;
  }
  cout << r << endl;
}
