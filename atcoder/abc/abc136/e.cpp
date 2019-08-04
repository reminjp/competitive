#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int s = 0;
  for (auto &e : a) {
    cin >> e;
    s += e;
  }

  set<int> d;
  for (int i = 1; i * i <= s; i++) {
    if (s % i == 0) {
      d.insert(i);
      d.insert(s / i);
    }
  }

  int m = 1;
  for (auto e : d) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = a[i] % e;
    sort(begin(v), end(v));

    int kt = k;
    for (int l = 0, r = n - 1; l < r;) {
      if (v[l] == 0) {
        l++;
      } else if (v[r] == e) {
        r--;
      } else {
        int t = min(v[l], e - v[r]);
        kt -= t;
        v[l] -= t;
        v[r] += t;
      }
    }
    if (kt >= 0) m = max(m, e);
  }
  cout << m << endl;
}
