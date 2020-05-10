#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1e18 + 1;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto& e : a) {
    cin >> e;
    e--;
  }

  ll i = 0;
  vector<ll> d(n, INF);
  d[0] = 0;
  while (k > 0) {
    if (d[a[i]] != INF && d[a[i]] <= d[i] && (d[i] + 1) - d[a[i]] < k) {
      k %= (d[i] + 1) - d[a[i]];
    } else {
      if (d[a[i]] == INF) d[a[i]] = d[i] + 1;
      i = a[i];
      k--;
    }
  }
  for (auto e : d) cerr << e << ' ';
  cerr << endl;
  cout << i + 1 << endl;
}
