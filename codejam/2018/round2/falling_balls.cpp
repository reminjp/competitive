#include <bits/stdc++.h>
using namespace std;

void solve() {
  int c;
  cin >> c;
  vector<int> b(c);
  for (auto& e : b) {
    cin >> e;
  }
  if (b.front() == 0 || b.back() == 0) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  for (int i = 1; i < c; i++) {
    b[i] += b[i - 1];
  }

  vector<int> m{0}, r{0};
  for (int k = 0, i = 0; i < c;) {
    if (i + 1 < b[k]) {
      i++;
    } else if (i + 1 > b[k]) {
      k++;
    } else {
      m.push_back(k);
      r.push_back(i);
      i++;
      k++;
    }
  }

  int h = 0;
  for (int i = 1; i < m.size(); i++) {
    h = max(h, max(m[i] - (r[i - 1] + 1), r[i] - m[i]));
  }
  h = h + 1;
  vector<vector<char>> a(h, vector<char>(c, '.'));
  for (int i = 1; i < m.size(); i++) {
    for (int j = 1; j <= m[i] - (r[i - 1] + 1); j++) {
      a[h - 1 - j][m[i] - j] = '\\';
    }
    for (int j = 1; j <= r[i] - m[i]; j++) {
      a[h - 1 - j][m[i] + j] = '/';
    }
  }

  cout << h << endl;
  for (auto row : a) {
    for (auto e : row) {
      cout << e;
    }
    cout << endl;
  }
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
