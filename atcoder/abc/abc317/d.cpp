#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1e18;

template <class T>
void set_if_less(T& a, T b) {
  if (a > b) a = b;
}

int main() {
  int n;
  cin >> n;

  ll d = 0;
  vector<pair<ll, ll>> a;
  for (int i = 0; i < n; i++) {
    ll x, y, z;
    cin >> x >> y >> z;
    if (x < y) {
      d -= z;
      a.push_back({(y - x + 1) / 2, 2 * z});
    } else {
      d += z;
    }
  }

  if (d > 0) {
    cout << 0 << endl;
    return 0;
  }

  vector<ll> dp((ll)3e5 + 1, INF);
  dp[0] = 0;
  for (auto [c, z] : a) {
    for (int i = -d - 1; i >= 0; i--) {
      set_if_less(dp[i + z], dp[i] + c);
    }
  }

  cout << *min_element(dp.begin() + -d, dp.end()) << endl;
}
