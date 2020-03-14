#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll sqrtll(ll a) {
  ll x = 1;
  while (x * x <= a) x++;
  return x - 1;
}

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  cout << (a + sqrtll(4 * a * b) + b < c ? "Yes" : "No") << endl;
}
