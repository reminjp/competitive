#include <bits/stdc++.h>
using namespace std;

int days(int y, int m, int d) {
  if (m <= 2) {
    y -= 1;
    m += 12;
  }
  return 365 * y + y / 4 - y / 100 + y / 400 + 306 * (m + 1) / 10 + d - 429;
}

int main() {
  int y, m, d;
  cin >> y >> m >> d;
  cout << days(2014, 5, 17) - days(y, m, d) << endl;
}
