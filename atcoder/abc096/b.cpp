#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  cout << a + b + c + ((1 << k) - 1) * max(a, max(b, c)) << endl;
  return 0;
}
