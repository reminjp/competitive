#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> x(n + 1);
  for (int i = 1; i < n + 1; i++) {
    ll d;
    cin >> d;
    x[i] = x[i - 1] - d;
  }
  for (; q > 0; q--) {
    ll t, l, r;
    cin >> t >> l >> r;
    int il = partition_point(begin(x), end(x), [t, l](int e) { return e + t >= l; }) - begin(x);
    int ir = partition_point(begin(x), end(x), [t, r](int e) { return e + t > r; }) - begin(x);
    cout << il - ir << endl;
  }
}
