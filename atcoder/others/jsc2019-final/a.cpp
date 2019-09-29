#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (auto &e : a) cin >> e;
  for (auto &e : b) cin >> e;

  map<int, pair<int, int>> p;

  int x, y, z, w = -1;
  for (int t = 0; t < 2e6; t++) {
    int i = rand() % n, j = rand() % m;
    if (p.count(a[i] + b[j])) {
      if (p[a[i] + b[j]].first != i) {
        x = p[a[i] + b[j]].first;
        y = p[a[i] + b[j]].second;
        z = i;
        w = j;
        break;
      }
    } else {
      p[a[i] + b[j]] = make_pair(i, j);
    }
  }

  if (w == -1) {
    cout << -1 << endl;
  } else {
    cout << x << ' ' << y << ' ' << z << ' ' << w << ' ' << endl;
  }
}
