#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int r;
  if (a >= 13) {
    r = b;
  } else if (a >= 6) {
    r = b / 2;
  } else {
    r = 0;
  }
  cout << r << endl;
}
