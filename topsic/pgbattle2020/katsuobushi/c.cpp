#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;

int main() {
  ll n, m, d;
  cin >> n >> m >> d;
  vector<int> a(m);
  for (auto& e : a) {
    cin >> e;
    e--;
  }

  map<ll, set<ll>> ms;
  for (auto e : a) {
    ms[e % d].insert(e / d);
  }

  mint r = 0;
  r += (mint)((n - 1) % d + 1) * ((n - 1) / d + 2) * ((n - 1) / d + 1) / 2;
  r += (mint)(d - ((n - 1) % d + 1)) * ((n - 1) / d + 1) * ((n - 1) / d) / 2;

  for (const auto& [k, s] : ms) {
    vector<ll> v(s.begin(), s.end());
    v.insert(v.begin(), -1);
    v.push_back((n - 1) / d + (k <= (n - 1) % d ? 1 : 0));

    r -= (mint)(v.back() + 1) * v.back() / 2;

    for (ll i = 0; i + 1 < v.size(); i++) {
      mint vd = v[i + 1] - v[i] - 1;
      r += (vd + 1) * vd / 2;
    }
  }

  cout << r.val() << endl;
}
