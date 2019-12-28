#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = 0;
  for (auto e : s) {
    if ('0' <= e && e <= '9') {
      n *= 10;
      n += e - '0';
    } else {
      cout << "error" << endl;
      return 0;
    }
  }
  cout << 2 * n << endl;
}
