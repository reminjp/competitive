#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto& e : a) cin >> e.first >> e.second;

  map<pair<int, int>, int> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      m[{a[j].first - a[i].first, a[j].second - a[i].second}]++;
    }
  }

  int r = n;
  for (auto e : m) {
    r = min(r, n - e.second);
  }
  cout << r << endl;
}
