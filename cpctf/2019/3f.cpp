#include <bits/stdc++.h>
using namespace std;

int f(string s) { return s[0] == 'B' ? -(s[1] - '0') : s[0] - '1'; }

int main() {
  string x, y;
  cin >> x >> y;
  cout << f(x) - f(y) << endl;
}
