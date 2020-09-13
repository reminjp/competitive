#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  ll s_min = 2e9, s_max = -2e9, d_min = 2e9, d_max = -2e9;
  while (n--) {
    ll x, y;
    cin >> x >> y;
    s_min = min(s_min, x + y);
    s_max = max(s_max, x + y);
    d_min = min(d_min, x - y);
    d_max = max(d_max, x - y);
  }
  cout << max(s_max - s_min, d_max - d_min) << endl;
}
