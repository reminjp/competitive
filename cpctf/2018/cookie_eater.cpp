#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> c(h, vector<int>(w, 1e9));
  c[h - 1][w - 1] = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(h - 1, w - 1));
  while (!q.empty()) {
    int y1 = q.front().first, x1 = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int y2 = y1 + dy[i], x2 = x1 + dx[i];
      if (0 <= y2 && y2 < h && 0 <= x2 && x2 < w) {
        int c2 = c[y1][x1] + max(0, a[y1][x1] - (a[y2][x2] + 1));
        if (a[y2][x2] - 1 <= a[y1][x1] && c2 < c[y2][x2]) {
          c[y2][x2] = c2;
          q.push(make_pair(y2, x2));
        }
      }
    }
  }
  cout << (c[0][0] == 1e9 ? -1 : c[0][0]) << endl;
  return 0;
}
