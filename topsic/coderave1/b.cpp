#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &e : a) cin >> e;
  for (auto &e : b) cin >> e;
  int r = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < b[i]) r = i;
  }
  cout << r + 1 << endl;
}
