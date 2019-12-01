#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  ll r = 1;
  map<int, int> m;
  m[0] = 3;
  for (auto e : a) {
    r *= m[e];
    r %= MOD;
    if (m[e] == 0) break;
    m[e]--;
    m[e + 1]++;
  }
  cout << r << endl;
}
