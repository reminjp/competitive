#include <bits/stdc++.h>
using namespace std;

int n, m;
bool won[9][9], used[9][9];

int dfs(int x, int y) {
  // cerr << x << " " << y << endl;
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     cerr << (used[i][j] ? "-+"[won[i][j]] : '.') << " ";
  //   }
  //   cerr << endl;
  // }
  if (x == n) return 1;
  if (y == n) return dfs(x + 1, 0);
  if (x == y || used[x][y]) return dfs(x, y + 1);

  int x_wins = 0, x_losses = 0;
  for (int i = 0; i < n; i++) {
    if (x == i || !used[x][i]) continue;
    x_wins += won[x][i];
    x_losses += !won[x][i];
  }
  int y_wins = 0, y_losses = 0;
  for (int i = 0; i < n; i++) {
    if (i == y || !used[i][y]) continue;
    y_wins += !won[i][y];
    y_losses += won[i][y];
  }

  int r = 0;
  if (x_wins < n / 2 && y_losses < n / 2) {
    won[x][y] = true;
    won[y][x] = false;
    used[x][y] = used[y][x] = true;
    r += dfs(x, y + 1);
    used[x][y] = used[y][x] = false;
  }
  if (x_losses < n / 2 && y_wins < n / 2) {
    won[x][y] = false;
    won[y][x] = true;
    used[x][y] = used[y][x] = true;
    r += dfs(x, y + 1);
    used[x][y] = used[y][x] = false;
  }
  return r;
}

int main() {
  while (cin >> n, n) {
    fill(won[0], won[n], false);
    fill(used[0], used[n], false);
    cin >> m;
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      won[x][y] = true;
      used[x][y] = used[y][x] = true;
    }

    bool valid = true;
    for (int i = 0; i < n; i++) {
      int wins = 0, losses = 0;
      for (int j = 0; j < n; j++) {
        if (i == j || !used[i][j]) continue;
        wins += won[i][j];
        losses += !won[i][j];
      }
      valid &= wins <= n / 2 && losses <= n / 2;
    }

    cout << (valid ? dfs(0, 0) : 0) << endl;
  }
}
