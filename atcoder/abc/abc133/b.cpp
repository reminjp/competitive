#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  vector<vector<int>> x(n, vector<int>(d));
  for (auto& p : x) {
    for (auto& e : p) {
      cin >> e;
    }
  }
  int r = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int p = 0;
      for (int k = 0; k < d; k++) p += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
      r += p == int(sqrt(p)) * int(sqrt(p));
    }
  }
  cout << r << endl;
}
