#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i + 1];
    a[i + 1] += a[i];
  }
  for (int k = 1; k <= n; k++) {
    ll r = 0;
    for (int i = 0; i < n - k + 1; i++) {
      r = max(r, a[i + k] - a[i]);
    }
    cout << r << endl;
  }
}
