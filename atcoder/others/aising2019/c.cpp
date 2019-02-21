#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int h, w;
vector<string> s;
vector<vector<bool>> v;

array<int, 2> dfs(int y, int x) {
  array<int, 2> r = {0, 0};
  r[s[y][x] == '#']++;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i], nx = x + dx[i];
    if (!(0 <= ny && ny < h && 0 <= nx && nx < w) || v[ny][nx] || s[ny][nx] == s[y][x]) continue;
    v[ny][nx] = true;
    auto t = dfs(ny, nx);
    r[0] += t[0];
    r[1] += t[1];
  }
  return r;
}

int main() {
  cin >> h >> w;
  s = vector<string>(h);
  v = vector<vector<bool>>(h, vector<bool>(w));
  for (auto &e : s) {
    cin >> e;
  }
  ll r = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (v[i][j]) continue;
      v[i][j] = true;
      auto t = dfs(i, j);
      r += (ll)t[0] * t[1];
    }
  }
  cout << r << endl;
}
