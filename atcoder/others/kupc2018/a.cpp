#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> s(n), a(n);
  for (auto &e : s) cin >> e;
  for (auto &e : a) cin >> e;
  int r = 0;
  for (int i = 0; i < n; i++) {
    r = max(r, s[i] * a[i]);
  }
  cout << r << endl;
}
