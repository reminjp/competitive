#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  ll r = 0;
  while (n--) {
    ll a, b;
    cin >> a >> b;
    r += (b - a + 1) * (a + b) / 2;
  }
  cout << r << endl;
}
