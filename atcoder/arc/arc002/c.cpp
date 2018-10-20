#include <bits/stdc++.h>
using namespace std;

int main() {
  const string b = "ABXY";
  int n;
  string c;
  cin >> n >> c;
  int m = 0;
  for (auto l1 : b) {
    for (auto l2 : b) {
      for (auto r1 : b) {
        for (auto r2 : b) {
          int k = 0;
          for (int i = 0; i < n - 1; i++) {
            if ((c[i] == l1 && c[i + 1] == l2) || (c[i] == r1 && c[i + 1] == r2)) {
              k++;
              i++;
            }
          }
          m = max(m, k);
        }
      }
    }
  }
  cout << n - m << endl;
  return 0;
}
