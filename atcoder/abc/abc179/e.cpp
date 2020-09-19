#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, x, m;
  cin >> n >> x >> m;

  vector<ll> v{0, x};
  ll h;
  {
    set<ll> s{x};
    ll e = x;
    while (s.count(e = e * e % m) == 0) {
      v.push_back(e);
      s.insert(e);
    }
    h = find(v.begin(), v.end(), e) - v.begin() - 1;
  }
  ll l = v.size() - 1;
  bool z = v.back() == 0;
  for (int i = 0; i + 1 < v.size(); i++) v[i + 1] += v[i];

  ll r = 0;
  if (n < h || z) {
    r += v[min(l, n)];
  } else {
    r += (n - h) / (l - h) * (v[l] - v[h]);
    r += v[h + (n - h) % (l - h)];
  }
  cout << r << endl;
}
