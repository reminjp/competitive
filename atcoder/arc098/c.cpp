#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<vector<int>> m(n + 1, vector<int>(2));
  for (int i = 0; i < n; i++) {
    m[i + 1][s[i] == 'E'] = 1;
  }
  for (int i = 0; i < n; i++) {
    m[i + 1][0] += m[i][0];
    m[i + 1][1] += m[i][1];
  }
  int r = n;
  for (int i = 0; i < n; i++) {
    r = min(r, (m[i][0] - m[0][0]) + (m[n][1] - m[i + 1][1]));
  }
  cout << r << endl;
  return 0;
}
