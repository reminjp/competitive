#include <bits/stdc++.h>
using namespace std;

int main() {
  int sum = 0, a = 1, b = 2;
  while (a <= 4000000) {
    if (a % 2 == 0) sum += a;
    int c = a + b;
    a = b;
    b = c;
  }
  cout << sum << endl;
}
