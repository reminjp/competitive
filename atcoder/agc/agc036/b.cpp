#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  vector<int> t(n, -1);
  {
    vector<int> u(2e5 + 1, -1);
    for (int _ = 0; _ < 2; _++) {
      for (int i = n - 1; i >= 0; i--) {
        if (t[i] == -1 && u[a[i]] != -1) t[i] = u[a[i]];
        u[a[i]] = i;
      }
    }
  }

  vector<int> r;
  vector<int> v(n, -1);
  for (ll i = 0, j = 0; i < k; j++, i += j / n, j %= n) {
    if (v[j] != -1 && i + (i - v[j]) < k) i += (k - i - 1) / (i - v[j]) * (i - v[j]);
    v[j] = i;

    if (j < t[j]) {
      j = t[j];
    } else if (i + 1 < k) {
      i++;
      j = t[j];
    } else {
      r.push_back(a[j]);
    }
  }

  for (auto e : r) cout << e << ' ';
  cout << endl;
}
