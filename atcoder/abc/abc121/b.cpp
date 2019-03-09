#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> b(m);
  for (auto &e : b) {
    cin >> e;
  }
  int r = 0;
  for (; n > 0; n--) {
    vector<int> a(m);
    for (auto &e : a) {
      cin >> e;
    }
    int s = c;
    for (int i = 0; i < m; i++) {
      s += a[i] * b[i];
    }
    r += s > 0;
  }
  cout << r << endl;
}
