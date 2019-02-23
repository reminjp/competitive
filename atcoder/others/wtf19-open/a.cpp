#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v.push_back({a, i + 1});
  }
  sort(rbegin(v), rend(v));
  vector<int> r = {v.front().second};
  v.front().first--;
  for (; k >= 0; k--) {
    int t = r.back();
    sort(rbegin(v), rend(v));
    bool ng = false;
    for (auto& e : v) {
      if (e.second == t) continue;
      r.push_back(e.second);
      e.first--;
      ng |= e.first < 0;
    }
    if (ng) break;
  }
  if (k == -1) {
    cout << r.size() << endl;
    for (auto e : r) {
      cout << e << " ";
    }
    cout << endl;
  } else {
    cout << -1 << endl;
  }
}
