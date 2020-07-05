#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> v(h);
  for (auto& e : v) cin >> e;

  int r = 0;
  for (int a = 0; a < (1 << h); a++) {
    for (int b = 0; b < (1 << w); b++) {
      int x = 0;
      for (int i = 0; i < h; i++) {
        if (a >> i & 1) continue;
        for (int j = 0; j < w; j++) {
          if (b >> j & 1) continue;
          if (v[i][j] == '#') x++;
        }
      }
      if (x == k) r++;
    }
  }
  cout << r << endl;
}
