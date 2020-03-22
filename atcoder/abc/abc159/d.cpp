#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, ll> m;
  for (auto& e : a) {
    cin >> e;
    m[e]++;
  }

  ll s = 0;
  for (auto e : m) s += e.second * (e.second - 1) / 2;

  for (auto e : a) {
    ll d = -(m[e] * (m[e] - 1) / 2) + ((m[e] - 1) * (m[e] - 2) / 2);
    cout << s + d << '\n';
  }
  cout << flush;
}
