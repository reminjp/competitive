#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  ll s = 0;
  for (auto& e : a) {
    cin >> e;
    s += e;
  }
  if (s < m) {
    cout << -1 << endl;
    return 0;
  }
  sort(rbegin(a), rend(a));

  int ng = 0, ok = n;
  while (ng < ok - 1) {
    int d = (ng + ok - 1) / 2 + 1;
    ll p = 0;
    for (int i = 0; i < n; i++) {
      p += max(0, a[i] - i / d);
    }
    if (p < m) {
      ng = d;
    } else {
      ok = d;
    }
  }
  cout << ok << endl;
}
