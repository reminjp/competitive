#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
  int h, w, x;
  cin >> h >> w >> x;
  vector<string> s(h);
  for (auto &e : s) {
    cin >> e;
  }

  queue<pair<int, int>> q;
  vector<vector<int>> d(h, vector<int>(w, 1e9));
  int sy, sx, gy, gx;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      switch (s[i][j]) {
        case 'S': {
          sy = i;
          sx = j;
          break;
        }
        case 'G': {
          gy = i;
          gx = j;
          break;
        }
        case '@': {
          q.push({i, j});
          d[i][j] = 0;
          break;
        }
      }
    }
  }

  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    for (int k = 0; k < 4; k++) {
      int i = p.first + dy[k], j = p.second + dx[k];
      if (s[i][j] != '#' && d[i][j] > d[p.first][p.second] + 1) {
        d[i][j] = d[p.first][p.second] + 1;
        q.push({i, j});
      }
    }
  }

  vector<vector<int>> r(h, vector<int>(w, 1e9));
  if (d[sy][sx] > x) {
    q.push({sy, sx});
    r[sy][sx] = 0;
  }
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    for (int k = 0; k < 4; k++) {
      int i = p.first + dy[k], j = p.second + dx[k];
      if (s[i][j] != '#' && d[i][j] > x && r[i][j] > r[p.first][p.second] + 1) {
        r[i][j] = r[p.first][p.second] + 1;
        q.push({i, j});
      }
    }
  }
  cout << (r[gy][gx] != 1e9 ? r[gy][gx] : -1) << endl;
}
