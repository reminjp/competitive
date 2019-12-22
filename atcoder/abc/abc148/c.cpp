#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
  ll a, b;
  cin >> a >> b;
  cout << a / gcd(a, b) * b << endl;
}
