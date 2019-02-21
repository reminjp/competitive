#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, n;
  string x;
  cin >> a >> b >> n >> x;
  for (auto e : x) {
    if (e == 'E' ? a >= b : e == 'S') {
      if (a) {
        a--;
      }
    } else {
      if (b) {
        b--;
      }
    }
  }
  cout << a << endl << b << endl;
  return 0;
}
