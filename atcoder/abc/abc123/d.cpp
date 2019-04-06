#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<vector<ll>> a = {vector<ll>(x), vector<ll>(y), vector<ll>(z)};
  for (auto &e : a[0]) cin >> e;
  for (auto &e : a[1]) cin >> e;
  for (auto &e : a[2]) cin >> e;
  for (auto &e : a) {
    sort(rbegin(e), rend(e));
  }
  vector<ll> r = a[0];
  for (int i = 1; i < a.size(); i++) {
    vector<ll> t;
    for (int p = 0; p < r.size(); p++) {
      for (int q = 0; q < a[i].size(); q++) {
        t.push_back(r[p] + a[i][q]);
      }
    }
    sort(rbegin(t), rend(t));
    r = vector<ll>(begin(t), begin(t) + min(k, (int)t.size()));
  }
  for (auto e : r) cout << e << endl;
}
