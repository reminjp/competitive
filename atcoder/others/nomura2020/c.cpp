#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n + 1);
  for (auto& e : a) cin >> e;

  if (n == 0) {
    cout << (a[0] == 1 ? 1 : -1) << endl;
    return 0;
  }
  if (a[0] != 0) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 0; i + 1 < n + 1; i++) a[i + 1] += a[i];
  bool valid = true;
  ll k = 1, l = 1;
  for (int i = 1; i < n + 1; i++) {
    ll l2 = min(2 * l, a[n] - a[i - 1]);
    if (l2 < a[i] - a[i - 1]) {
      valid = false;
      break;
    }
    k += l2;
    l = l2 - (a[i] - a[i - 1]);
  }
  if (l > 0) valid = false;

  cout << (valid ? k : -1) << endl;
}
