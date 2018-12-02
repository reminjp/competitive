#include <bits/stdc++.h>
using namespace std;

int h, w, s;
vector<vector<int>> u;
vector<vector<vector<vector<pair<int, int>>>>> dp;

int sum(int y1, int x1, int y2, int x2) { return u[y2 + 1][x2 + 1] - u[y1][x2 + 1] - u[y2 + 1][x1] + u[y1][x1]; }

pair<int, int> dfs(int y1, int x1, int y2, int x2) {
  if (dp[y1][x1][y2][x2] != pair<int, int>{0, 0}) {
    return dp[y1][x1][y2][x2];
  }
  pair<int, int> r = {1, s - u[h][w] + sum(y1, x1, y2, x2)};
  for (int i = y1; i < y2; i++) {
    if (s - u[h][w] + sum(y1, x1, i, x2) >= 0 && s - u[h][w] + sum(i + 1, x1, y2, x2) >= 0) {
      auto r1 = dfs(y1, x1, i, x2);
      auto r2 = dfs(i + 1, x1, y2, x2);
      r = max(r, {r1.first + r2.first, min(r1.second, r2.second)});
    }
  }
  for (int i = x1; i < x2; i++) {
    if (s - u[h][w] + sum(y1, x1, y2, i) >= 0 && s - u[h][w] + sum(y1, i + 1, y2, x2) >= 0) {
      auto r1 = dfs(y1, x1, y2, i);
      auto r2 = dfs(y1, i + 1, y2, x2);
      r = max(r, {r1.first + r2.first, min(r1.second, r2.second)});
    }
  }
  return dp[y1][x1][y2][x2] = r;
}

int main() {
  while (cin >> h >> w >> s, h) {
    u = vector<vector<int>>(h + 1, vector<int>(w + 1));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> u[i + 1][j + 1];
        u[i + 1][j + 1] += u[i][j + 1] + u[i + 1][j] - u[i][j];
      }
    }
    dp = vector<vector<vector<vector<pair<int, int>>>>>(
        h, vector<vector<vector<pair<int, int>>>>(w, vector<vector<pair<int, int>>>(h, vector<pair<int, int>>(w))));
    auto r = dfs(0, 0, h - 1, w - 1);
    cout << r.first << " " << r.second << endl;
  }
}
