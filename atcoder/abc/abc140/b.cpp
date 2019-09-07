#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n - 1);
  for (auto &e : a) cin >> e;
  for (auto &e : b) cin >> e;
  for (auto &e : c) cin >> e;
  int r = 0;
  for (auto e : a) r += b[e - 1];
  for (int i = 0; i + 1 < n; i++) {
    if (a[i] + 1 == a[i + 1]) r += c[a[i] - 1];
  }
  cout << r << endl;
}
