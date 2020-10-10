#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (auto& e : s) cin >> e;

  int r = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') continue;
      if (i + 1 < h && s[i + 1][j] != '#') r++;
      if (j + 1 < w && s[i][j + 1] != '#') r++;
    }
  }
  cout << r << endl;
}
