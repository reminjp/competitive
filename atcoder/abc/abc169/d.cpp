#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;

  ll r = 0;
  for (ll z = 2; z * z <= n; z++) {
    ll x = 0;
    while (n % z == 0) {
      n /= z;
      x++;
    }
    for (ll i = 1; i <= x; i++) {
      r++;
      x -= i;
    }
  }
  if (n > 1) r++;

  cout << r << endl;
}
