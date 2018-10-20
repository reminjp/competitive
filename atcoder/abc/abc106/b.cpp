#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m = 8;
  cin >> n;
  int r = 0;
  for (int i = 1; i <= n; i += 2) {
    int c = 0;
    for (int j = 1; j <= i; j++) {
      c += i % j == 0;
    }
    if (c == m) {
      r++;
    }
  }
  cout << r << endl;
}
