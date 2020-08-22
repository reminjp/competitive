#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& e : a) cin >> e;

  ll r = 0;
  for (int i = 1; i < n; i++) {
    ll d = max(0ll, a[i - 1] - a[i]);
    a[i] += d;
    r += d;
  }
  cout << r << endl;
}
