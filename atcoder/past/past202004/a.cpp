#include <bits/stdc++.h>
using namespace std;

int f(const string& s) {
  if (s[0] == 'B') return -(s[1] - '0');
  return s[0] - '0' - 1;
}

int main() {
  string s, t;
  cin >> s >> t;
  cout << abs(f(t) - f(s)) << endl;
}
