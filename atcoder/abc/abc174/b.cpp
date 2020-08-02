#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, d;
  cin >> n >> d;
  int r = 0;
  while (n--) {
    ll x, y;
    cin >> x >> y;
    if (x * x + y * y <= d * d) r++;
  }
  cout << r << endl;
}
