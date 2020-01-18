#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    int x, l;
    cin >> x >> l;
    v[i].first = x + l;
    v[i].second = x - l;
  }
  sort(v.begin(), v.end());
  int r = 0, t = -1e9;
  for (auto e : v) {
    if (e.second < t) continue;
    t = e.first;
    r++;
  }
  cout << r << endl;
}
