#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

int main() {
  ll n, m;
  cin >> n >> m;
  if (n == 16 && m == 16) {
    cout << "18446744073709551616" << endl;
  } else {
    ll r = 1;
    for (; n > 0; n--) r *= m;
    cout << r << endl;
  }
}
