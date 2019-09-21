#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  int r = n - k + 1;

  vector<int> c(n);
  c[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) c[i] = a[i] < a[i + 1] ? c[i + 1] + 1 : 1;
  int t = 0;
  for (auto e : c) t += e >= k;
  r -= max(0, t - 1);

  set<int> s;
  for (int i = 0; i < k; i++) s.insert(a[i]);
  for (int i = 0; i + k < n; i++) {
    r -= c[i] < k && a[i] == *s.begin() && a[i + k] > *s.rbegin();
    s.erase(a[i]);
    s.insert(a[i + k]);
  }

  cout << r << endl;
}
