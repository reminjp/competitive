#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int z = 0;
  if (2 * c < a + b) {
    int t = min(x, y);
    x -= t;
    y -= t;
    z += 2 * t;
  }
  if (2 * c < a) {
    int t = x;
    x -= t;
    z += 2 * t;
  }
  if (2 * c < b) {
    int t = y;
    y -= t;
    z += 2 * t;
  }
  cout << a * x + b * y + c * z << endl;
  return 0;
}
