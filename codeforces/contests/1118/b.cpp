#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(2, vector<int>(n + 1));
  for (int i = 0; i < n; i++) {
    cin >> a[i % 2][i + 1];
  }
  for (int i = 0; i < n; i++) {
    a[0][i + 1] += a[0][i];
    a[1][i + 1] += a[1][i];
  }
  int r = 0;
  for (int i = 0; i < n; i++) {
    r += (a[0][i] - a[0][0]) + (a[1][n] - a[1][i + 1]) == (a[1][i] - a[1][0]) + (a[0][n] - a[0][i + 1]);
  }
  cout << r << endl;
}
