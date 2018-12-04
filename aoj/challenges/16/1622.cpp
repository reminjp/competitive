#include <bits/stdc++.h>
using namespace std;

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

int main() {
  int h, w;
  while (cin >> h >> w, h) {
    vector<vector<bool>> a(h + 2, vector<bool>(w + 2));
    for (int i = 0; i < h; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < w; j++) {
        a[i + 1][j + 1] = s[j] == '.';
      }
    }

    vector<vector<int>> v(h + 2, vector<int>(w + 2));
    int y = 1, x = 1, d = 0, c = 0;
    while (!(y == 1 && x == 1 && d == 3)) {
      if (!a[y + dy[d]][x + dx[d]]) {
        d = (d + 1) % 4;
        continue;
      }
      y += dy[d];
      x += dx[d];
      d = (d + 3) % 4;
      c += (y == 1 || y == h) && (x == 1 || x == w);
      v[y][x] |= 1 << c;
    }

    bool r = v[1][1] && v[1][w] && v[h][1] && v[h][w];
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        if ((i == 1 || i == h) && (j == 1 || j == w)) continue;
        r &= bitset<8>(v[i][j]).count() <= 1;
      }
    }
    cout << (r ? "YES" : "NO") << endl;
  }
}
