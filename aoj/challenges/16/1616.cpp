#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m, n) {
    vector<int> a(n);
    for (auto& e : a) {
      cin >> e;
    }
    int r = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (a[i] + a[j] <= m) {
          r = max(r, a[i] + a[j]);
        }
      }
    }
    if (r) {
      cout << r << endl;
    } else {
      cout << "NONE" << endl;
    }
  }
}
