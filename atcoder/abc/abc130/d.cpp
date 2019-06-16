#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i + 1];
    a[i + 1] += a[i];
  }
  ll r = 0;
  for (int i = 0; i < n; i++) {
    int b = lower_bound(begin(a), end(a), a[i] + k) - begin(a);
    r += n + 1 - b;
  }
  cout << r << endl;
}
