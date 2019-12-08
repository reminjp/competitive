#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> a(n);
  for (auto& e : a) {
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      e.push_back({x - 1, y});
    }
  }

  int r = 0;
  for (int b = 0; b < (1 << n); b++) {
    bool valid = true;
    for (int i = 0; i < n; i++) {
      if (!((b >> i) & 1)) continue;
      for (auto e : a[i]) valid = valid && ((b >> e.first) & 1) == e.second;
    }
    if (valid) {
      bitset<16> bs(b);
      r = max(r, (int)bs.count());
    }
  }
  cout << r << endl;
}
