#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> desk_top(n), container_next(n, -1);
  iota(desk_top.begin(), desk_top.end(), 0);
  while (q--) {
    int f, t, x;
    cin >> f >> t >> x;
    f--, t--, x--;
    int p = container_next[x];
    container_next[x] = desk_top[t];
    desk_top[t] = desk_top[f];
    desk_top[f] = p;
  }

  vector<int> r(n);
  for (int i = 0; i < n; i++) {
    int p = desk_top[i];
    while (p != -1) {
      r[p] = i;
      p = container_next[p];
    }
  }
  for (auto e : r) cout << e + 1 << endl;
}
