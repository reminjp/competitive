#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  double m = 0;
  for (auto &e : a) {
    cin >> e;
    m += e;
  }
  m /= n;
  int r = 0;
  for (int i = 0; i < n; i++) {
    if (abs(a[i] - m) < abs(a[r] - m)) {
      r = i;
    }
  }
  cout << r << endl;
}
