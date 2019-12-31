#include <bits/stdc++.h>
using namespace std;

bool IsLeapYear(int y) { return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0); }

int main() {
  int y;
  cin >> y;
  cout << (IsLeapYear(y) ? "YES" : "NO") << endl;
}
