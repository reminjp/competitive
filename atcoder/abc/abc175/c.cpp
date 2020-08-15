#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll x, k, d;
  cin >> x >> k >> d;
  x = abs(x);

  ll r;
  if (k <= x / d) {
    r = x - k * d;
  } else if ((k - x / d) % 2 == 0) {
    r = x % d;
  } else {
    r = d - x % d;
  }
  cout << r << endl;
}
