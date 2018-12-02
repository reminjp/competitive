#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n, n) {
    vector<string> s(n);
    for (auto& e : s) {
      cin >> e;
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; s[i][j] == '.'; j++) {
        if (j + 1 < s[i].size() && s[i][j + 1] != '.') {
          s[i][j] = '+';
        } else if (i + 1 < n && j < s[i + 1].size() && (s[i + 1][j] == '+' || s[i + 1][j] == '|')) {
          s[i][j] = '|';
        } else {
          s[i][j] = ' ';
        }
      }
    }
    for (auto e : s) {
      cout << e << endl;
    }
  }
}
