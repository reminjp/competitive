#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> x(n);
  for (auto &e : x) {
    cin >> e;
  }
  ll r = 1e9;
  for (int i = 0; i < n - k + 1; i++) {
    ll a = abs(x[i]), b = abs(x[i + k - 1]);
    if (x[i] * x[i + k - 1] >= 0) {
      r = min(r, max(a, b));
    } else {
      r = min(r, min(a, b) + a + b);
    }
  }
  cout << r << endl;
}
