#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;

  int r = 0;
  while (a >= b) {
    b *= 2;
    r++;
  }
  while (b >= c) {
    c *= 2;
    r++;
  }
  cout << (r <= k ? "Yes" : "No") << endl;
}
