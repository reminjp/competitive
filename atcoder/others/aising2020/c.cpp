#include <bits/stdc++.h>
using namespace std;

int f(int x, int y, int z) { return x * x + y * y + z * z + x * y + y * z + z * x; }

int main() {
  int n;
  cin >> n;

  vector<int> r(n + 1);
  for (int x = 1; f(x, 1, 1) <= n; x++) {
    for (int y = 1; f(x, y, 1) <= n; y++) {
      for (int z = 1; f(x, y, z) <= n; z++) {
        r[f(x, y, z)]++;
      }
    }
  }

  for (int i = 1; i <= n; i++) cout << r[i] << endl;
}
