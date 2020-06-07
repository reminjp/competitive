#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<bool>> solved(n, vector<bool>(m));
  vector<int> score(m, n);
  while (q--) {
    int s, t, u;
    cin >> s;
    if (s == 1) {
      cin >> t;
      t--;
      int r = 0;
      for (int i = 0; i < m; i++) {
        if (solved[t][i]) r += score[i];
      }
      cout << r << endl;
    } else {
      cin >> t >> u;
      t--, u--;
      solved[t][u] = true;
      score[u]--;
    }
  }
}
