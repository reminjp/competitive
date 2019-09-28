#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, m, t, k;
  cin >> n >> m >> t >> k;
  vector<vector<tuple<int, ll, ll>>> v(n);
  for (int i = 0; i < m; i++) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    b--;
    v[a].push_back(make_tuple(b, c, d));
    v[b].push_back(make_tuple(a, c, d));
  }

  vector<ll> d(n, 1e18);
  priority_queue<pair<ll, int>> q;
  q.push(make_pair(0, 0));
  while (!q.empty()) {
    int i = q.top().second;
    ll di = -q.top().first;
    q.pop();
    if (d[i] <= di) continue;
    d[i] = di;
    for (auto e : v[i]) {
      int j = get<0>(e);
      ll dj = di + get<1>(e);
      if (get<2>(e) > k && t - (get<2>(e) - k) - get<1>(e) < di && di < t + (get<2>(e) - k))
        dj = (t + (get<2>(e) - k)) + get<1>(e);
      if (d[j] > dj) q.push(pair<ll, int>{-dj, j});
    }
  }
  cout << (d[n - 1] != ll(1e18) ? d[n - 1] : -1) << endl;
}
