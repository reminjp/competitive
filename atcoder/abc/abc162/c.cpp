#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  ll r = 0;
  for (ll a = 1; a <= n; a++) {
    for (ll b = 1; b <= n; b++) {
      for (ll c = 1; c <= n; c++) {
        r += gcd(gcd(a, b), c);
      }
    }
  }
  cout << r << endl;
}
