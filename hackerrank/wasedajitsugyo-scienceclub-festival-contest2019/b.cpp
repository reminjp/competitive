#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, n;
  cin >> t >> n;
  vector<pair<int, int>> a(n);
  for (auto &e : a) cin >> e.first >> e.second;
  sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
  int r = 0, ct = 0;
  for (auto e : a) {
    if (e.first < ct || e.second > t) continue;
    ct = e.second;
    r++;
  }
  cout << r << endl;
}
