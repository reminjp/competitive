#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &e : a) cin >> e;
  sort(begin(a), end(a));
  for (int i = 0; i < n - 1; i += 2) {
    if (a[i] + a[i + 1] < 0) {
      a[i] *= -1;
      a[i + 1] *= -1;
    }
  }
  ll r = 0;
  for (auto e : a) r += e;
  cout << r << endl;
}
