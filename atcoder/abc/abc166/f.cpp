#include <bits/stdc++.h>
using namespace std;
constexpr int M = 2;

int main() {
  int n;
  cin >> n;
  array<int, 3> a;
  for (auto &e : a) cin >> e;
  vector<string> s(n);
  for (auto &e : s) cin >> e;

  for (auto &e : a) e = min(e, M);

  vector<char> r, t;
  vector<vector<vector<bool>>> v(n, vector<vector<bool>>(3 * M + 1, vector<bool>(3 * M + 1)));
  auto dfs = [&](auto &&dfs, int i) {
    if (i == n) {
      r = t;
      return;
    }
    if (v[i][a[0]][a[1]]) return;
    v[i][a[0]][a[1]] = true;
    for (int k = 0; k < 2; k++) {
      int x = s[i][k] - 'A';
      int y = s[i][1 - k] - 'A';
      if (a[x] <= 0) continue;
      a[x]--;
      a[y]++;
      t.push_back('A' + y);
      dfs(dfs, i + 1);
      t.pop_back();
      a[x]++;
      a[y]--;
    }
  };
  dfs(dfs, 0);

  if (r.empty()) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    for (auto e : r) cout << e << endl;
  }
}
