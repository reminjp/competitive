#include <bits/stdc++.h>
using namespace std;

int main() {
  int l, r, d;
  cin >> l >> r >> d;
  int m = 0;
  for (int i = l; i <= r; i++) {
    if (i % d == 0) m++;
  }
  cout << m << endl;
}
