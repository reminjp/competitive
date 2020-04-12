#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  ll r = 0;
  for (ll i = 1; i <= n; i++) {
    if (i % 3 && i % 5) r += i;
  }
  cout << r << endl;
}
