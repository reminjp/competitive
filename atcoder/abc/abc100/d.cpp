#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> x(n), y(n), z(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> z[i];
  }
  ll r = 0;
  for (auto sx : {-1, 1}) {
    for (auto sy : {-1, 1}) {
      for (auto sz : {-1, 1}) {
        vector<ll> v(n);
        for (int i = 0; i < n; i++) {
          v[i] = sx * x[i] + sy * y[i] + sz * z[i];
        }
        sort(rbegin(v), rend(v));
        ll s = 0;
        for (int i = 0; i < m; i++) {
          s += v[i];
        }
        r = max(r, s);
      }
    }
  }
  cout << r << endl;
  return 0;
}
