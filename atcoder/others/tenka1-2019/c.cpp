#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<vector<int>> v(2, vector<int>(n + 2));
  for (int i = 0; i < n; i++) {
    v[0][i + 1] = s[i] == '#';
    v[1][i + 1] = s[i] == '.';
  }
  for (int i = 0; i < n - 1; i++) {
    v[0][i + 2] += v[0][i + 1];
    v[1][n - i - 1] += v[1][n - i];
  }
  int r = n;
  for (int i = 0; i < n + 1; i++) {
    r = min(r, v[0][i] + v[1][i + 1]);
  }
  cout << r << endl;
}
