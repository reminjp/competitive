#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, ll> memo;

ll f(ll n) {
  if (memo.count(n)) return memo[n];
  if (n < 2) return memo[n] = 0;
  if (n % 2) return memo[n] = 2 * f(n / 2);
  return memo[n] = 1 + f(n / 2 - 1) + f(n / 2);
}

int main() {
  ll n;
  cin >> n;
  cout << f(n - 2) << endl;
}
