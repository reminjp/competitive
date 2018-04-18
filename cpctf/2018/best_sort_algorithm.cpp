#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &e : a) {
    cin >> e;
  }
  int m = 0;
  for (int i = 0; i < n; i++) {
    while (a[i] != i + 1) {
      int t = a[i];
      a[i] = a[t - 1];
      a[t - 1] = t;
      m++;
    }
  }
  cout << m << endl;
  return 0;
}
