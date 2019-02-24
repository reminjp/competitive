#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b, q;
  cin >> a >> b >> q;
  vector<vector<ll>> s = {vector<ll>(a), vector<ll>(b)};
  for (auto& e : s[0]) cin >> e;
  for (auto& e : s[1]) cin >> e;
  for (; q > 0; q--) {
    ll x;
    cin >> x;
    vector<vector<ll>::iterator> it = {lower_bound(begin(s[0]), end(s[0]), x), lower_bound(begin(s[1]), end(s[1]), x)};
    vector<vector<ll>> v(2);
    for (int i = 0; i < 2; i++) {
      if (it[i] != begin(s[i])) {
        v[i].push_back(*(it[i] - 1));
      }
      if (it[i] != end(s[i])) {
        v[i].push_back(*it[i]);
      }
    }
    ll r = 1e18;
    for (auto e0 : v[0]) {
      for (auto e1 : v[1]) {
        r = min(r, min(abs(e0 - x), abs(e1 - x)) + abs(e0 - e1));
      }
    }
    cout << r << endl;
  }
}
