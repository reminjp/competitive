#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 998244353;

int main() {
  int n;
  cin >> n;
  vector<int> d(n), m(n);
  for (auto &e : d) {
    cin >> e;
    m[e]++;
  }

  if (d[0] != 0 || m[0] != 1) {
    cout << 0 << endl;
    return 0;
  }

  ll r = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m[i]; j++) {
      r *= m[i - 1];
      r %= MOD;
    }
  }
  cout << r << endl;
}
