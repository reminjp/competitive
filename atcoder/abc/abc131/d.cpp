#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto &e : a) cin >> e.second >> e.first;
  sort(begin(a), end(a));
  bool r = true;
  int t = 0;
  for (auto e : a) {
    t += e.second;
    r &= t <= e.first;
    if (!r) break;
  }
  cout << (r ? "Yes" : "No") << endl;
}
