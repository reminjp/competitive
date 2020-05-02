#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> d(n, vector<int>(n, 1e9));
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    d[i][a - 1] = 1;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
      }
    }
  }
  for (int i = 0; i < n; i++) cout << d[i][i] << ' ';
  cout << endl;
}
