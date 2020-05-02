#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (auto& e : s) cin >> e;

  int w = 2 * n - 1;
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] != '#') continue;
      if (j - 1 >= 0 && s[i + 1][j - 1] == 'X' || s[i + 1][j] == 'X' || j + 1 < w && s[i + 1][j + 1] == 'X') {
        s[i][j] = 'X';
      }
    }
  }

  for (const auto& e : s) cout << e << '\n';
  cout << flush;
}
