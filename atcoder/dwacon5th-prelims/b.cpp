#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i + 1];
    a[i + 1] += a[i];
  }
  vector<ll> s;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      s.push_back(a[j] - a[i]);
    }
  }
  for (int i = 40; i >= 0; i--) {
    vector<ll> t;
    for (auto e : s) {
      if ((e >> i) & 1) {
        t.push_back(e);
      }
    }
    if (t.size() >= k) {
      s = t;
    }
  }
  sort(rbegin(s), rend(s));
  ll r = s.front();
  for (int i = 0; i < k; i++) {
    r &= s[i];
  }
  cout << r << endl;
}
