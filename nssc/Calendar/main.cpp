#include <bits/stdc++.h>
using namespace std;

bool is_leap_year(int y) {
  if (y % 4 == 0) return true;
  if (y % 100 == 0) return false;
  if (y % 400 == 0) return true;
  return true;
}

vector<vector<int>> d_max{{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                          {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

struct date {
  int y, m, d;
  bool leap;

  date(const string& s) {
    y = 1000 * (s[0] - '0') + 100 * (s[1] - '0') + 10 * (s[2] - '0') + (s[3] - '0');
    m = 10 * (s[5] - '0') + (s[6] - '0');
    d = 10 * (s[8] - '0') + (s[9] - '0');
    leap = is_leap_year(y);
  }

  void increment() {
    d++;
    if (d > d_max[leap][m - 1]) {
      d = 1;
      m++;
      if (m > 12) {
        m = 1;
        y++;
        leap = is_leap_year(y);
      }
    }
  }

  bool equals(const date& a) const { return y == a.y && m == a.m && d == a.d; }

  int count1234() const {
    auto s = to_string(y) + to_string(m) + to_string(d);
    return count_if(s.begin(), s.end(), [](char c) { return c == '1' || c == '2' || c == '3' || c == '4'; });
  }
};

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  date d1(s1), d2(s2);

  d2.increment();

  int r = 0;
  for (date d = d1; !d.equals(d2); d.increment()) {
    r += d.count1234() == 5;
  }
  cout << r << endl;
}
