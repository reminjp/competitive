#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) cin >> e;
  sort(begin(a), end(a));

  vector<pair<int, int>> v;
  int m;
  if (n == 2) {
    v.push_back({a[1], a[0]});
    m = v.front().first - v.front().second;
  } else {
    int b = upper_bound(begin(a), end(a), 0) - begin(a);
    if (b == 0) b = 1;
    if (b == n) b = n - 1;

    if (b == n - 1) {
      m = a[b];
      for (int i = 0; i < b; i++) {
        v.push_back({m, a[i]});
        m = m - a[i];
      }
    } else {
      m = a[0];
      for (int i = b; i < n - 1; i++) {
        v.push_back({m, a[i]});
        m = m - a[i];
      }
      v.push_back({a[n - 1], m});
      m = a[n - 1] - m;
      for (int i = 1; i < b; i++) {
        v.push_back({m, a[i]});
        m = m - a[i];
      }
    }
  }
  cout << m << endl;
  for (auto e : v) cout << e.first << ' ' << e.second << endl;
}
