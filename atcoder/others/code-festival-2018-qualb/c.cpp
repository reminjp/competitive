#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> a(n, string(n, '.'));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j % 5 == i * 2 % 5) {
        a[i][j] = 'X';
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!(i - 1 >= 0 && a[i - 1][j] != '.' || i + 1 < n && a[i + 1][j] != '.' || j - 1 >= 0 && a[i][j - 1] != '.' ||
            j + 1 < n && a[i][j + 1] != '.')) {
        a[i][j] = 'X';
      }
    }
  }
  for (auto e : a) {
    cout << e << endl;
  }
}
