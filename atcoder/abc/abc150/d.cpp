#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (auto& e : a) cin >> e;

  ll k = 1;
  for (auto e : a) k = lcm(k, e / 2);
  bool b = true;
  for (auto e : a) b = b && k / (e / 2) % 2 == 1;

  cout << (b ? (m / k + 1) / 2 : 0) << endl;
}
