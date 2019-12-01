#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int r = -1;
  for (int x = 0; x <= n; x++) {
    if (int(1.08 * x) == n) {
      r = x;
      break;
    }
  }
  if (r == -1) {
    cout << ":(" << endl;
  } else {
    cout << r << endl;
  }
}
