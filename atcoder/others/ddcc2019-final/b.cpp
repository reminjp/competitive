#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, k, r;
  cin >> n >> k >> r;

  vector<ll> m(n);
  ll s = 0;
  for (int i = k; i < n; i++) {
    m[i] = i - k + 1;
    s += m[i];
  }
  if (s < r) {
    cout << "No Luck" << endl;
    return 0;
  }
  vector<bool> b(n);
  for (int i = n - 1; i >= 0; i--) {
    if (s - m[i] >= r) {
      s -= m[i];
      b[i] = true;
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    if (b[i]) cout << n - i << " ";
  }
  for (int i = 0; i < n; i++) {
    if (!b[i]) cout << n - i << " ";
  }
  cout << endl;
}
