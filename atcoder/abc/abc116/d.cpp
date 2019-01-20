#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> v(n);
  for (int i = 0; i < n; i++) {
    int t, d;
    cin >> t >> d;
    v[t - 1].push_back(d);
  }
  vector<ll> a{0}, b{0};
  for (auto &e : v) {
    if (e.empty()) {
      continue;
    }
    sort(begin(e), end(e));
    a.push_back(e.back());
    for (auto it = begin(e); it != end(e) - 1; it++) {
      b.push_back(*it);
    }
  }
  sort(rbegin(a), rend(a) - 1);
  sort(rbegin(b), rend(b) - 1);
  for (int i = 0; i + 1 < a.size(); i++) {
    a[i + 1] += a[i];
  }
  for (int i = 0; i + 1 < b.size(); i++) {
    b[i + 1] += b[i];
  }
  ll r = 0;
  for (ll x = max(1, k - ((int)b.size() - 1)); x <= min(k, (int)a.size() - 1); x++) {
    r = max(r, a[x] + b[k - x] + x * x);
  }
  cout << r << endl;
}
