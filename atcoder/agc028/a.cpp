#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
  ll n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  ll d = gcd(n, m);
  bool is_good = true;
  for (ll i = 0; i < d; i++) is_good &= s[n / d * i] == t[m / d * i];
  cout << (is_good ? n * m / d : -1) << endl;
}
