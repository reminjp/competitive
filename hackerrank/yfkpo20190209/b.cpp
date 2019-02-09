#include <bits/stdc++.h>
using namespace std;

int main() {
  string s = "yfkpo";
  int k, y, x;
  cin >> k >> y >> x;
  y--;
  x--;
  int r = y * k + (y % 2 ? k - 1 - x : x);
  cout << s[r % s.size()] << endl;
}
