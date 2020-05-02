#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(1 << n);
  for (auto& e : a) cin >> e;

  vector<vector<int>> m(n);
  for (int i = 0; i < n; i++) {
    m[i].resize(1 << n - (i + 1));
    for (int j = 0; j < (1 << n); j++) {
      int j2 = j / (1 << i + 1);
      m[i][j2] = max(m[i][j2], a[j]);
    }
  }

  for (int j = 0; j < (1 << n); j++) {
    for (int i = 0; i < n; i++) {
      int j2 = j / (1 << i + 1);
      if (a[j] < m[i][j2] || i == n - 1) {
        cout << i + 1 << endl;
        break;
      }
    }
  }
}
