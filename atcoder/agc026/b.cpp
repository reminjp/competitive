#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return a % b ? gcd(b, a % b) : b; }

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    bool r = false;
    if (a - b >= 0 && d >= b) {
      ll k = gcd(b, d);
      ll x = a <= c ? a + ((c - a) / k + 1) * k : c + (a - c - 1) % k + 1;
      r = x - b >= 0;
    }
    cout << (r ? "Yes" : "No") << endl;
  }
}
