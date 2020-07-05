#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 1e9 + 7;

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto& e : a) cin >> e;

  vector<ll> ne, po;
  for (auto e : a) {
    if (e < 0) {
      ne.push_back(e);
    } else if (e > 0) {
      po.push_back(e);
    }
  }

  ll r = 1;

  if (k == n) {
    bool b = false;
    for (auto e : a) {
      (r *= abs(e)) %= MOD;
      if (e < 0) b = !b;
    }
    if (b) r = (MOD - r) % MOD;
    cout << r << endl;
    return 0;
  }

  if (ne.size() - ne.size() % 2 + po.size() >= k && (po.size() > 0 || k % 2 == 0)) {
    sort(ne.begin(), ne.end());
    sort(po.rbegin(), po.rend());
    int i = 0, j = 0;
    if (k % 2 == 1) {
      r = po[0];
      j++;
    }
    while (i + j < k) {
      if (i + 1 < ne.size() && (j + 1 >= po.size() || ne[i] * ne[i + 1] > po[j] * po[j + 1])) {
        r *= ne[i] * ne[i + 1] % MOD;
        i += 2;
      } else {
        r *= po[j] * po[j + 1] % MOD;
        j += 2;
      }
      r %= MOD;
    }
  } else if (n - (ne.size() + po.size()) > 0) {
    r = 0;
  } else {
    sort(ne.rbegin(), ne.rend());
    for (int i = 0; i < k; i++) (r *= -ne[i]) %= MOD;
    r = (MOD - r) % MOD;
  }
  cout << r << endl;
}
