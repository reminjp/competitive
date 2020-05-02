#include <bits/stdc++.h>
using namespace std;

template <class T>
inline vector<T> vec(size_t n, T a) {
  return vector<T>(n, a);
}

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  for (auto& e : a) cin >> e;

  int sy, sx;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] == 'S') {
        sy = i;
        sx = j;
      }
    }
  }

  int r = 1e9;

  queue<tuple<int, int, int, int>> q;
  q.push({sy, sx, 0, 0});
  auto visited = vec(h, vec(w, vec(10, false)));
  visited[sy][sx][0] = true;
  while (!q.empty()) {
    auto [y, x, z, d] = q.front();
    q.pop();
    if (z == 9 && a[y][x] == 'G') {
      r = min(r, d);
      break;
    } else if (a[y][x] - '0' == z + 1 && !visited[y][x][z + 1]) {
      visited[y][x][z + 1] = true;
      q.push({y, x, z + 1, d});
    }
    for (int i = 0; i < 4; i++) {
      int y2 = y + dy[i], x2 = x + dx[i];
      if ((unsigned)y2 >= h || (unsigned)x2 >= w) continue;
      if (visited[y2][x2][z]) continue;
      visited[y2][x2][z] = true;
      q.push({y2, x2, z, d + 1});
    }
  }

  cout << (r == 1e9 ? -1 : r) << endl;
}
