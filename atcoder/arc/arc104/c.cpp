#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e4;

int main() {
  int n;
  cin >> n;
  vector<int> v(2 * n);
  bool valid = true;
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    if (a != -1) {
      if (v[a - 1]) valid = false;
      v[a - 1] = i;
    }
    if (b != -1) {
      if (v[b - 1]) valid = false;
      v[b - 1] = -i;
    }
  }

  if (!valid) {
    cout << "No" << endl;
    return 0;
  }

  auto dfs = [&](auto&& dfs, int i, int c, int to, int done) -> bool {
    // cerr << i << endl;
    // for (auto e : v) cerr << e << ' ';
    // cerr << endl;
    if (i == 2 * n) {
      // cerr << "done " << done << endl;
      return done == n;
    }

    if (i > to) c = 0;

    bool r = false;
    if (v[i] > 0) {
      int bi = find(v.begin(), v.end(), -v[i]) - v.begin();
      if (bi == 2 * n) {
        if (c) {
          if (i + c < 2 * n) {
            if (v[i + c] == 0) {
              v[i + c] = -v[i];
              r |= dfs(dfs, i + 1, c, i + c, done + 1);
              v[i + c] = 0;
            }
          }
        } else {
          for (int c2 = 1; !r && i + c2 < 2 * n; c2++) {
            if (v[i + c2] != 0) continue;
            v[i + c2] = -v[i];
            r |= dfs(dfs, i + 1, c2, i + c2, done + 1);
            v[i + c2] = 0;
          }
        }
      } else if (i < bi) {
        if (c) {
          if (i + c < 2 * n) {
            if (i + c == bi) {
              r |= dfs(dfs, i + 1, c, i + c, done + 1);
            }
          }
        } else {
          r |= dfs(dfs, i + 1, bi - i, bi, done + 1);
        }
      }
    } else if (v[i] < 0) {
      if (find(v.begin(), v.end(), -v[i]) != v.end()) {
        r |= dfs(dfs, i + 1, c, to, done);
      }
    } else {
      if (c) {
        if (i + c < 2 * n) {
          if (v[i + c] == 0) {
            v[i] = INF;
            v[i + c] = -INF;
            r |= dfs(dfs, i + 1, c, i + c, done + 1);
            v[i] = 0;
            v[i + c] = 0;
          } else {
            if (find(v.begin(), v.end(), -v[i + c]) == v.end()) {
              v[i] = -v[i + c];
              r |= dfs(dfs, i + 1, c, i + c, done + 1);
              v[i] = 0;
            }
          }
        }
      } else {
        for (int c2 = 1; !r && i + c2 < 2 * n; c2++) {
          if (v[i + c2] == 0) {
            v[i] = INF;
            v[i + c2] = -INF;
            r |= dfs(dfs, i + 1, c2, i + c2, done + 1);
            v[i] = 0;
            v[i + c2] = 0;
          } else {
            if (find(v.begin(), v.end(), -v[i + c2]) == v.end()) {
              v[i] = -v[i + c2];
              r |= dfs(dfs, i + 1, c2, i + c2, done + 1);
              v[i] = 0;
            }
          }
        }
      }
    }
    return r;
  };

  cout << (dfs(dfs, 0, 0, 0, 0) ? "Yes" : "No") << endl;
}
