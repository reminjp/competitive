#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    if (a.empty() || a.back() != e) a.push_back(e);
  }
  n = a.size();

  vector<int> v(n, n);
  {
    map<int, int> m;
    for (int i = n - 1; i >= 0; i--) {
      if (m.count(a[i])) {
        v[i] = m[a[i]];
      }
      m[a[i]] = i;
    }
  }

  vector<ll> dp(n + 1);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    dp[i + 1] += dp[i];
    dp[i + 1] %= mod;
    dp[v[i]] += dp[i];
    dp[v[i]] %= mod;
  }
  cout << dp[n - 1] << endl;
}
