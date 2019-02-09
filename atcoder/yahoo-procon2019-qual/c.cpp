#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll k, a, b;
  cin >> k >> a >> b;
  ll r = 1;
  r += min(k, a - 1);
  k -= r - 1;
  r += -a + b > 2 ? k / 2 * (-a + b) + k % 2 : k;
  cout << r << endl;
}
