#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  vector<set<int>> s(n);
  int t = 0;
  for (auto e : a) {
    int i;
    for (i = t; i > 0; i--) {
      auto it = s[i - 1].lower_bound(e);
      if (it != s[i - 1].end() && *it - e <= k) break;
      if (it != s[i - 1].begin() && e - *(--it) <= k) break;
    }
    s[i].insert(e);
    t = max(t, i + 1);
  }
  cout << t << endl;
}
