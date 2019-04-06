#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 5;
  vector<int> a(n);
  for (auto &e : a) {
    cin >> e;
  }
  int r = 0, d = 0;
  for (auto e : a) {
    r += ((e - 1) / 10 + 1) * 10;
    d = max(d, 9 - (e - 1) % 10);
  }
  cout << r - d << endl;
}
