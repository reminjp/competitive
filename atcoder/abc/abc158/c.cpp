#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int r = -1;
  for (int i = 0; i < 20 * b; i++) {
    if (int(0.08 * i) == a && int(0.1 * i) == b) {
      r = i;
      break;
    }
  }
  cout << r << endl;
}
