#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll n, p;
  cin >> n >> p;
  ll r = 1;
  if (n == 1) {
    r = p;
  } else if (n < 40) {
    for (int i = 1; i <= p; i++) {
      ll x = pow(i, n);
      if (x > p) break;
      if (p % x == 0) r = i;
    }
  }
  cout << r << endl;
}
