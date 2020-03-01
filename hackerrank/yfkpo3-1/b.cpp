#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

int main() {
  ll n;
  cin >> n;
  ll r = 1;
  for (ll i = 2; i <= n; i += 2) r = r * i % MOD;
  cout << r << endl;
}
