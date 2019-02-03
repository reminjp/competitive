#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> x(m);
  for (auto &e : x) {
    cin >> e;
  }
  sort(begin(x), end(x));
  vector<int> d(m - 1);
  for (int i = 0; i < m - 1; i++) {
    d[i] = x[i + 1] - x[i];
  }
  sort(begin(d), end(d));
  int r = 0;
  for (int i = 0; i < m - n; i++) {
    r += d[i];
  }
  cout << r << endl;
}
