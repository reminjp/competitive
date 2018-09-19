#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, l, r;
  while (cin >> n >> l >> r, n) {
    vector<int> a(n);
    for (auto& e : a) {
      cin >> e;
    }
    int m = 0;
    for (int i = l; i <= r; i++) {
      bool u = n % 2 == 0;
      for (int j = 0; j < n; j++) {
        if (i % a[j] == 0) {
          u = j % 2 == 0;
          break;
        }
      }
      m += u;
    }
    cout << m << endl;
  }
}
