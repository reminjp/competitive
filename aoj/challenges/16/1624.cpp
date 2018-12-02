#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n, n) {
    vector<int> a(n);
    int s = 0;
    for (auto &e : a) {
      cin >> e;
      s += e;
    }
    double m = (double)s / n;
    int r = 0;
    for (auto e : a) {
      r += e <= m;
    }
    cout << r << endl;
  }
}
