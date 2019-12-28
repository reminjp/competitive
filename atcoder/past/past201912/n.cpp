#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, w, c;
  cin >> n >> w >> c;
  map<ll, pair<ll, ll>> m;
  m[0] = {0, 0};
  m[w] = {0, 0};
  for (int i = 0; i < n; i++) {
    ll l, r, p;
    cin >> l >> r >> p;
    m[l].first += p;
    m[r].second -= p;
  }
  vector<pair<ll, pair<ll, ll>>> v(m.begin(), m.end());
  // for (auto e : v) cerr << e.first << ' ' << e.second.first << ' ' << e.second.second << endl;

  ll a = 1e18;
  for (ll i = 0, j = 0, s = 0; j < v.size();) {
    if (v[i].first + c <= v[j].first) {
      a = min(a, s);
      i++;
      s += v[i].second.second;
    } else {
      s += v[j].second.first;
      j++;
    }
    // cerr << "(" << v[i].first << ' ' << v[j].first << ") " << s << endl;
  }
  cout << a << endl;
}
