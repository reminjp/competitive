#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  vector<ll> t(2), a(2), b(2), d(2);
  cin >> t[0] >> t[1] >> a[0] >> a[1] >> b[0] >> b[1];

  for (int i = 0; i < 2; i++) d[i] = t[i] * a[i] - t[i] * b[i];
  for (int i = 0; i + 1 < 2; i++) d[i + 1] += d[i];

  if (d[1] == 0) {
    cout << "infinity" << endl;
    return 0;
  } else if (d[1] < 0) {
    for (int i = 0; i < 2; i++) d[i] = -d[i];
  }

  if (d[0] > 0) {
    cout << 0 << endl;
  } else {
    cout << -d[0] / d[1] * 2 + int(-d[0] % d[1] != 0) << endl;
  }
}
