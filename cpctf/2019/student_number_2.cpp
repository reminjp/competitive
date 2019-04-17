#include <bits/stdc++.h>
using namespace std;

bool f(string a) {
  int s = 0;
  for (int i = 0; i < a.size() - 1; i++) s += (a[i] - '0') * (2 + i);
  return s % 11 % 10 == a.back() - '0';
}

int main() {
  string y, x, a;
  cin >> y >> x;
  a = y + x;
  string r, t;
  for (int i = 0; r.empty() && i < a.size(); i++) {
    for (char c = '0'; r.empty() && c <= '9'; c++) {
      if (a[i] == c) continue;
      t = a;
      t[i] = c;
      if (f(t)) r = t;
    }
  }
  cout << (r.empty() ? "NO" : r.substr(0, 2) + " " + r.substr(2)) << endl;
}
