#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  ll r = 0;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i) continue;
    if (i - 1 && n / (i - 1) == n % (i - 1)) r += i - 1;
    if (i * i != n && n / (n / i - 1) == n % (n / i - 1)) r += n / i - 1;
  }
  cout << r << endl;
}
