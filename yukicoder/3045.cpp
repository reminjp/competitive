#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  if (n >= m) {
    cout << 0 << endl;
  } else {
    int r = 1;
    for (int i = 1; i <= n; i++) {
      r *= i;
      r %= m;
    }
    cout << r << endl;
  }
}
