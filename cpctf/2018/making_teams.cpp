#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> r(n);
  for (auto &e : r) {
    cin >> e;
  }
  int m = 0;
  for (auto e : r) {
    m += x <= e;
  }
  cout << min(n / 3, m / 2) << endl;
  return 0;
}
