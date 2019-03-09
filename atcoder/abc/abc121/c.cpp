#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(n);
  for (auto &e : a) {
    cin >> e.first >> e.second;
  }
  sort(begin(a), end(a));
  ll r = 0;
  for (auto e : a) {
    ll x = min(m, e.second);
    r += x * e.first;
    m -= x;
    if (!m) {
      break;
    }
  }
  cout << r << endl;
}
