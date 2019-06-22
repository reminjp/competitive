#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  cin >> s;
  int p = 0;
  function<int()> parse = [&]() {
    switch (s[p]) {
      case '(': {
        p++;
        int a = parse();
        char op = s[p];
        p++;
        int b = parse();
        p++;
        switch (op) {
          case '|': {
            return a | b;
          }
          case '&': {
            return a & b;
          }
          case '^': {
            return a ^ b;
          }
        }
      }
      case '0': {
        p++;
        return 0b00;
      }
      case '1': {
        p++;
        return 0b11;
      }
      case 'x': {
        p++;
        return 0b01;
      }
      case 'X': {
        p++;
        return 0b10;
      }
    }
    return 0;
  };
  int r = parse();
  cout << int((r & 1) != ((r >> 1) & 1)) << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
