#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MAX = 3234566667ll;

int main() {
  int k;
  cin >> k;

  set<ll> s;
  auto dfs = [&](auto&& dfs, ll a) {
    if (a > MAX) return;
    s.insert(a);
    for (ll d = max(0ll, a % 10 - 1); d <= min(9ll, a % 10 + 1); d++) dfs(dfs, 10 * a + d);
  };
  for (ll i = 1; i <= 9; i++) dfs(dfs, i);

  vector<ll> r(s.begin(), s.end());
  cout << r[k - 1] << endl;
}
