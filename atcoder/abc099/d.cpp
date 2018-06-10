#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, c;
  cin >> n >> c;
  vector<vector<int>> d(c, vector<int>(c));
  for (auto &r : d) {
    for (auto &e : r) {
      cin >> e;
    }
  }
  vector<vector<int>> a(3, vector<int>(c));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int e;
      cin >> e;
      a[(i + j) % 3][e - 1]++;
    }
  }

  int m = 1e9;
  vector<int> k(3);
  for (k[0] = 0; k[0] < c; k[0]++) {
    for (k[1] = 0; k[1] < c; k[1]++) {
      if (k[1] == k[0]) {
        continue;
      }
      for (k[2] = 0; k[2] < c; k[2]++) {
        if (k[2] == k[0] || k[2] == k[1]) {
          continue;
        }
        int s = 0;
        for (int i = 0; i < 3; i++) {
          for (int j = 0; j < c; j++) {
            s += a[i][j] * d[j][k[i]];
          }
        }
        m = min(m, s);
      }
    }
  }
  cout << m << endl;
  return 0;
}
