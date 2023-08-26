#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  for (auto& e : a) cin >> e;

  int sy, sx, gy, gx;
  vector m(h, vector<int>(w, false));
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      auto e = a[y][x];
      if (e == '.') {
        m[y][x] = true;
      } else if (e == 'S') {
        sy = y, sx = x;
        m[y][x] = true;
      } else if (e == 'G') {
        gy = y, gx = x;
        m[y][x] = true;
      }
    }
  }

  for (int y = 0; y < h; y++) {
    for (int x = 0, b = false; x < w; x++) {
      auto e = a[y][x];
      if (e == '#' || e == '>' || e == 'v' || e == '<' || e == '^') b = false;
      if (e == '>') b = true;
      if (b) m[y][x] = false;
    }
    for (int x = w - 1, b = false; x >= 0; x--) {
      auto e = a[y][x];
      if (e == '#' || e == '>' || e == 'v' || e == '<' || e == '^') b = false;
      if (e == '<') b = true;
      if (b) m[y][x] = false;
    }
  }
  for (int x = 0; x < w; x++) {
    for (int y = 0, b = false; y < h; y++) {
      auto e = a[y][x];
      if (e == '#' || e == '>' || e == 'v' || e == '<' || e == '^') b = false;
      if (e == 'v') b = true;
      if (b) m[y][x] = false;
    }
    for (int y = h - 1, b = false; y >= 0; y--) {
      auto e = a[y][x];
      if (e == '#' || e == '>' || e == 'v' || e == '<' || e == '^') b = false;
      if (e == '^') b = true;
      if (b) m[y][x] = false;
    }
  }

  // for (const auto& e : a) {
  //   for (auto e : e) cerr << (e ? '.' : '#');
  //   cerr << endl;
  // }
  // cerr << endl;

  vector v(h, vector(w, INF));
  v[sy][sx] = 0;
  queue<pair<int, int>> q;
  q.push({sy, sx});
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();
    for (int d = 0; d < 4; d++) {
      auto y2 = y + dy[d];
      auto x2 = x + dx[d];
      if (y2 < 0 || h <= y2 || x2 < 0 || w <= x2) continue;
      if (!m[y2][x2]) continue;
      if (v[y2][x2] != INF) continue;
      v[y2][x2] = v[y][x] + 1;
      q.push({y2, x2});
    }
  }

  cout << (v[gy][gx] == INF ? -1 : v[gy][gx]) << endl;
}
