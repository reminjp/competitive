#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 4;
  vector<vector<int>> a(n, vector<int>(n));
  for (auto& r : a) {
    for (auto& e : r) {
      cin >> e;
    }
  }
  bool r = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      r |= a[i][j] == a[i][j + 1];
      r |= a[j][i] == a[j + 1][i];
    }
  }
  cout << (r ? "CONTINUE" : "GAMEOVER") << endl;
}
