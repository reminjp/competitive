#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, l;
  cin >> n >> l;
  int r = n * (l + (l + n - 1)) / 2;
  if (0 < l) {
    r -= l;
  } else if (l + n - 1 < 0) {
    r -= l + n - 1;
  }
  cout << r << endl;
}
