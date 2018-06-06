#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i + 1];
  }

  for (int i = 0; i < n; i++) {
    a[i + 1] += a[i];
  }
  map<ll, ll> m;
  for (auto e : a) {
    m[e]++;
  }
  ll r = 0;
  for (auto e : m) {
    if (e.second > 1) {
      r += e.second * (e.second - 1) / 2;
    }
  }
  cout << r << endl;
  return 0;
}
