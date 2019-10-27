#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  ll r = n - 1;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      r = min(r, i + n / i - 2);
    }
  }
  cout << r << endl;
}
