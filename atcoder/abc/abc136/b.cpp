#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int r = 0;
  for (int i = 1; i <= n; i *= 100) {
    r += min(10 * i, n + 1) - i;
  }
  cout << r << endl;
}
