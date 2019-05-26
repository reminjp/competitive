#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> s(m);
  for (auto &e : s) {
    int k;
    cin >> k;
    e = vector<int>(k);
    for (auto &ee : e) {
      cin >> ee;
      ee--;
    }
  }
  vector<int> p(m);
  for (auto &e : p) cin >> e;

  int r = 0;
  for (int i = 0; i < (1 << n); i++) {
    bool b = true;
    for (int j = 0; j < m; j++) {
      int c = 0;
      for (auto e : s[j]) c += (i >> e) & 1;
      b &= c % 2 == p[j];
    }
    r += b;
  }
  cout << r << endl;
}
