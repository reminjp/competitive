#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (i + j != n / 2 * 2 + 1) {
        v.push_back({i, j});
      }
    }
  }
  cout << v.size() << endl;
  for (auto e : v) {
    cout << e.first << " " << e.second << endl;
  }
}
