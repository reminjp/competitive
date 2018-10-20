#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  for (auto &r : a) {
    for (auto &e : r) {
      cin >> e;
    }
  }

  vector<pair<pair<int, int>, pair<int, int>>> v;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w - 1; j++) {
      if (a[i][j] % 2) {
        v.push_back({{i, j}, {i, j + 1}});
        a[i][j]--;
        a[i][j + 1]++;
      }
    }
  }
  for (int i = 0; i < h - 1; i++) {
    if (a[i][w - 1] % 2) {
      v.push_back({{i, w - 1}, {i + 1, w - 1}});
      a[i][w - 1]--;
      a[i + 1][w - 1]--;
    }
  }

  cout << v.size() << endl;
  for (auto e : v) {
    auto s = e.first, d = e.second;
    cout << s.first + 1 << " " << s.second + 1 << " " << d.first + 1 << " " << d.second + 1 << endl;
  }
}
