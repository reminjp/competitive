#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, s;
  cin >> n >> s;

  vector<int> v(n);
  auto dfs = [&](auto&& dfs, int i, int t) -> void {
    if (i == n) {
      if (t == s) {
        for (auto e : v) cout << e << ' ';
        cout << endl;
      }
      return;
    }

    for (int e = i == 0 ? 1 : v[i - 1]; t + (n - i) * e <= s; e++) {
      v[i] = e;
      dfs(dfs, i + 1, t + e);
    }
  };
  dfs(dfs, 0, 0);
}
