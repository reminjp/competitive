#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& e : a) cin >> e;

  vector<ll> v;
  for (auto e : a) {
    if (v.empty()) {
      v.push_back(e);
    } else if ((v.size() % 2 != 0) == (v.back() < e)) {
      v.push_back(e);
    } else {
      v.back() = e;
    }
  }

  for (auto e : v) cerr << e << ' ';
  cerr << endl;

  ll r = 1000;
  for (int i = 0; i + 1 < v.size(); i += 2) r += (r / v[i]) * (v[i + 1] - v[i]);
  cout << r << endl;
}
