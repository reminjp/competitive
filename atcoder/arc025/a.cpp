#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 7;
  vector<int> d(n), j(n);
  for (auto &e : d) {
    cin >> e;
  }
  for (auto &e : j) {
    cin >> e;
  }
  int r = 0;
  for (int i = 0; i < n; i++) {
    r += max(d[i], j[i]);
  }
  cout << r << endl;
}
