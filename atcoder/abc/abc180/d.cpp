#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll x, y, a, b;
  cin >> x >> y >> a >> b;

  ll r = 0;
  while (x < b / (a - 1) && x < y / a) {
    x *= a;
    r++;
  }
  r += (y - x - 1) / b;
  cout << r << endl;
}
