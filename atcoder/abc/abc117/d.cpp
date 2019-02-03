#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &e : a) {
    cin >> e;
  }
  vector<vector<int>> v(40, vector<int>(2));
  for (int i = 0; i < v.size(); i++) {
    for (auto e : a) {
      v[i][0] += (e >> i) & 1;
      v[i][1] += !((e >> i) & 1);
    }
  }
  vector<ll> s(v.size() + 1), m(v.size() + 1);
  for (int i = 0; i < v.size(); i++) {
    s[i + 1] = s[i] + v[i][(k >> i) & 1] * (1ll << i);
    m[i + 1] = m[i] + max(v[i][0], v[i][1]) * (1ll << i);
  }
  ll r = s.back();
  for (int i = 0; i < v.size(); i++) {
    if ((k + 1 >> i) & 1) {
      r = max(r, (s.back() - s[i + 1]) + v[i][0] * (1ll << i) + (m[i] - m.front()));
    }
  }
  cout << r << endl;
}
