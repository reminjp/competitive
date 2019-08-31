#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int s = 32;
  vector<vector<int>> p(n + 1);
  for (int k = 2; k < p.size(); k++) {
    int t = k;
    for (int i = s - 4; i >= 2; i--) {
      while (t % i == 0) {
        p[k].push_back(i);
        t /= i;
      }
    }
    if (t > 1) p[k].clear();
  }
  int h = -1;
  for (int i = 0; i <= n - i; i++) {
    if ((i <= 1 || !p[i].empty()) && (n - i <= 1 || !p[n - i].empty())) {
      h = n - i;
      break;
    }
  }
  if (h == -1) return 1;

  vector<string> a(s, string(s, '#'));
  if (h != 0) {
    for (int i = 1; i < s - 1; i++) a[i][1] = '.';
    for (int i = 0; i < p[h].size(); i++) {
      for (int j = 0; j < p[h][i]; j++) a[3 * i + 3][j + 1] = a[3 * i + 4][j + 1] = '.';
    }
  }
  if (n - h != 0) {
    for (int i = 1; i < s - 1; i++) a[1][i] = a[s - 2][i] = a[i][s - 2] = '.';
    for (int i = 0; i < p[n - h].size(); i++) {
      for (int j = 0; j < p[n - h][i]; j++) a[3 * (8 - i) + 3][s - j - 2] = a[3 * (8 - i) + 4][s - j - 2] = '.';
    }
  }
  a[1][1] = 'S';
  a[s - 2][1] = 'G';

  cout << s << ' ' << s << endl;
  for (const auto& e : a) cout << e << endl;
}
