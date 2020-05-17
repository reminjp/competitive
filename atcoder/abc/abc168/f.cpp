#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int main() {
  int n, m;
  cin >> n >> m;
  map<ll, int> xm, ym;
  vector<ll> a(n), b(n), c(n), d(m), e(m), f(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
    xm.insert({a[i], 0});
    xm.insert({b[i], 0});
    ym.insert({c[i], 0});
  }
  for (int i = 0; i < m; i++) {
    cin >> d[i] >> e[i] >> f[i];
    xm.insert({d[i], 0});
    ym.insert({e[i], 0});
    ym.insert({f[i], 0});
  }

  int h = 2 * ym.size() + 1;
  int w = 2 * xm.size() + 1;
  vector<ll> xv(w, -1e9), yv(h, -1e9);
  {
    int i = 1;
    for (auto& e : xm) {
      xv[i] = xv[i + 1] = e.first;
      e.second = i;
      i += 2;
    }
  }
  {
    int i = 1;
    for (auto& e : ym) {
      yv[i] = yv[i + 1] = e.first;
      e.second = i;
      i += 2;
    }
  }

  vector<vector<bool>> v(h, vector<bool>(w));
  for (int i = 0; i < n; i++) {
    int y = ym[c[i]];
    for (int x = xm[a[i]], t = xm[b[i]]; x <= t; x++) v[y][x] = true;
  }
  for (int i = 0; i < m; i++) {
    int x = xm[d[i]];
    for (int y = ym[e[i]], t = ym[f[i]]; y <= t; y++) v[y][x] = true;
  }

  vector<vector<ll>> s(h, vector<ll>(w));
  for (int i = 2; i + 1 < h; i += 2) {
    for (int j = 2; j + 1 < w; j += 2) {
      s[i][j] = (yv[i + 1] - yv[i - 1]) * (xv[j + 1] - xv[j - 1]);
    }
  }

  int sy = lower_bound(yv.begin(), yv.end(), 0) - yv.begin() - 1;
  int sx = lower_bound(xv.begin(), xv.end(), 0) - xv.begin() - 1;

  // cerr << sy << ' ' << sx << endl;
  // for (int i = 0; i < h; i++) {
  //   for (int j = 0; j < w; j++) {
  //     if (i % 2 == 0 && j % 2 == 0) {
  //       cout << s[i][j];
  //     } else {
  //       cout << ".#"[v[i][j]];
  //     }
  //   }
  //   cout << endl;
  // }

  ll r = s[sy][sx];
  bool inf = false;
  vector<vector<bool>> visited(h, vector<bool>(w));
  visited[sy][sx] = true;
  queue<pair<int, int>> q;
  q.push({sy, sx});
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int y2 = y + dy[i], x2 = x + dx[i];
      if (unsigned(y2) >= h || unsigned(x2) >= w) {
        inf = true;
        continue;
      }
      if (v[y2][x2]) continue;
      if (visited[y2][x2]) continue;
      visited[y2][x2] = true;
      q.push({y2, x2});
      r += s[y2][x2];
    }
  }

  if (inf) {
    cout << "INF" << endl;
  } else {
    cout << r << endl;
  }
}
