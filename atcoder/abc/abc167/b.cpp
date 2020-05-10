#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  int r;
  if (k <= a) {
    r = k;
  } else if (k <= a + b) {
    r = a;
  } else {
    r = a - (k - a - b);
  }
  cout << r << endl;
}
