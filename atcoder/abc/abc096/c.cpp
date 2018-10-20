#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<bool>> a(h + 2, vector<bool>(w + 1));
  for (int i = 0; i < h; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < w; j++) {
      a[i + 1][j + 1] = s[j] == '#';
    }
  }
  bool r = true;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      r &= !a[i][j] || a[i + 1][j] || a[i][j + 1] || a[i - 1][j] || a[i][j - 1];
    }
  }
  cout << (r ? "Yes" : "No") << endl;
  return 0;
}
