#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<vector<pair<int, ll>>> c;
ll r = 0;

int dfs(int i) {
  if (c[i].empty()) {
    return 0;
  }
  vector<ll> v;
  for (const auto& e : c[i]) {
    v.push_back(e.second + dfs(e.first));
  }
  sort(begin(v), end(v));
  for (int k = 1; k < v.size(); k++) {
    r += v[k] * v[k];
  }
  return v.front();
}

int main() {
  cin >> n;
  c = vector<vector<pair<int, ll>>>(n);
  for (int i = 1; i < n; i++) {
    int p, l;
    cin >> p >> l;
    c[p - 1].push_back({i, l});
  }
  ll t = dfs(0);
  r += t * t;
  cout << r << endl;
}
