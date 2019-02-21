#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &e : a) {
    cin >> e;
  }
  sort(begin(a), end(a));
  vector<int> v(n);
  for (int i = 0; i < n - 1; i++) {
    int d = i % 2 ? -1 : 1;
    v[i] += d;
    v[i + 1] += -d;
  }
  sort(begin(v), end(v));
  ll s = 0, t = 0;
  for (int i = 0; i < n; i++) {
    s += v[i] * a[i];
    t += -v[n - i - 1] * a[i];
  }
  cout << max(s, t) << endl;
}
