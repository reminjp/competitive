#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int INF = 1e9 + 1;

void solve() {
  int n;
  cin >> n;

  vector<vector<ll>> a(n + 1), b(n + 1);
  ll s = 0;
  for (int i = 0; i < n; i++) {
    ll k, l, r;
    cin >> k >> l >> r;
    if (l >= r) {
      a[k - 1].push_back(l - r);
      s += r;
    } else {
      b[k].push_back(r - l);
      s += l;
    }
  }

  vector<ll> v(n, INF);
  {
    priority_queue<ll> q;
    for (int i = n - 1; i >= 0; i--) {
      for (auto e : a[i]) q.push(e);
      if (v[i] == INF && !q.empty()) {
        v[i] = q.top();
        q.pop();
      }
    }
  }
  sort(v.begin(), v.end());
  {
    priority_queue<ll> q;
    for (int i = 0; i < n; i++) {
      for (auto e : b[i]) q.push(e);
      if (v[i] == INF && !q.empty()) {
        v[i] = q.top();
        q.pop();
      }
    }
  }

  for (auto e : v) {
    if (e != INF) s += e;
  }
  cout << s << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
