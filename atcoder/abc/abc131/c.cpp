#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll f(ll n, ll d) { return n - n / d; }

ll f(ll n, ll c, ll d) { return f(n, c) + f(n, d) - f(n, c * d / gcd(c, d)); }

int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << f(b, c, d) - f(a - 1, c, d) << endl;
}
