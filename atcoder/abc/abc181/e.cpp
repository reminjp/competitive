#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> h(n), w(m);
  for (auto &e : h) cin >> e;
  for (auto &e : w) cin >> e;
  sort(h.begin(), h.end());

  vector<ll> ml(n), mr(n);
  for (int i = 2; i < n; i++) ml[i] = ml[i - 2] + (h[i - 1] - h[i - 2]);
  for (int i = n - 3; i >= 0; i--) mr[i] = mr[i + 2] + (h[i + 2] - h[i + 1]);

  ll r = 1e18;
  for (auto e : w) {
    int i = lower_bound(h.begin(), h.end(), e) - h.begin();
    i -= i % 2;
    r = min(r, ml[i] + mr[i] + abs(h[i] - e));
  }
  cout << r << endl;
}
