#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;

  ll r = n < 3 ? 1 : 2;
  for (ll k = 2; k * k <= n; k++) {
    ll t = n;
    while (t >= k) t % k ? t %= k : t /= k;
    if (t == 1) r++;

    if ((n - 1) % k == 0 && (n - 1) / k != k) r++;
  }

  cout << r << endl;
}
