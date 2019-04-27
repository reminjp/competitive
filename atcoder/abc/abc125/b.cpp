#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n), c(n);
  for (auto &e : v) cin >> e;
  for (auto &e : c) cin >> e;
  int r = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] > c[i]) r += v[i] - c[i];
  }
  cout << r << endl;
}
