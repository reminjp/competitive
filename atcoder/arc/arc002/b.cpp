#include <bits/stdc++.h>
using namespace std;

bool IsLeapYear(int y) { return y % 400 == 0 || y % 100 != 0 && y % 4 == 0; }

int LengthOfMonth(int y, int m) { return m == 2 ? 28 + IsLeapYear(y) : 30 + (m + (m >= 8)) % 2; }

std::tuple<int, int, int> ParseDate(const std::string& s) {
  int y = 1000 * (s[0] - '0') + 100 * (s[1] - '0') + 10 * (s[2] - '0') + (s[3] - '0');
  int m = 10 * (s[5] - '0') + (s[6] - '0');
  int d = 10 * (s[8] - '0') + (s[9] - '0');
  return std::make_tuple(y, m, d);
}

int main() {
  string s;
  cin >> s;
  int y, m, d;
  tie(y, m, d) = ParseDate(s);
  while (y % (m * d)) {
    d++;
    if (d > LengthOfMonth(y, m)) {
      m++;
      d = 1;
      if (m > 12) {
        y++;
        m = 1;
      }
    }
  }
  cout << setfill('0') << right;
  cout << setw(4) << y << '/';
  cout << setw(2) << m << '/';
  cout << setw(2) << d << endl;
}
