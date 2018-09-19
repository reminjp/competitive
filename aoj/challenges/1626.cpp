#include <bits/stdc++.h>
using namespace std;

int main() {
  int b;
  while (cin >> b, b) {
    int t, w;
    for (int i = 1e5; i >= 1; i--) {
      if (i % 2 != 0 && b % i == 0 || i % 2 == 0 && b % i != 0 && 2 * b % i == 0) {
        t = b / i - (i - 1) / 2;
        if (t >= 1) {
          w = i;
          break;
        }
      }
    }
    cout << t << " " << w << endl;
  }
}
