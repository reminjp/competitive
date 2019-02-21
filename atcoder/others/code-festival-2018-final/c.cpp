#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<pair<ll, ll>> a(n);
  for (auto &e : a) {
    cin >> e.first >> e.second;
  }
  sort(begin(a), end(a));
  int m;
  cin >> m;
  for (; m > 0; m--) {
    int t;
    cin >> t;
    int k = lower_bound(begin(a), end(a), pair<ll, ll>{t, 0}) - begin(a);
    ll r = 1e10;
    if (k - 1 >= 0) r = min(r, a[k - 1].second + t - a[k - 1].first);
    if (k < n) r = min(r, a[k].second);
    cout << r << endl;
  }
}
