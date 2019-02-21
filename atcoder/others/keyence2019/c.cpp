#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &e : a) cin >> e;
  for (auto &e : b) cin >> e;

  vector<ll> d(n + 1), s(n + 1);
  for (int i = 0; i < n; i++) d[i + 1] = a[i] - b[i];
  sort(begin(d) + 1, end(d));
  for (int i = 0; i < n; i++) s[i + 1] = s[i] + d[i + 1];
  int p = lower_bound(begin(d) + 1, end(d), 0) - begin(d);
  int r = -1;
  for (int i = 0; i <= n; i++) {
    if ((s[p - 1] - s[0]) + (s[n] - s[n - i]) >= 0) {
      r = p - 1 + i;
      break;
    }
  }
  cout << r << endl;
}
