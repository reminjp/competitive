#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    v[i] = {0, i + 1};
  }
  for (int i = 0; i < m; i++) {
    int e;
    cin >> e;
    v[e - 1].first = -(i + 1);
  }
  sort(begin(v), end(v));
  for (auto e : v) {
    cout << e.second << endl;
  }
}
