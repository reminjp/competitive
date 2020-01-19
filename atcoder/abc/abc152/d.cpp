#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> m(10, vector<int>(10));
  for (int i = 1; i <= n; i++) {
    auto s = to_string(i);
    m[s.front() - '0'][s.back() - '0']++;
  }
  int r = 0;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      r += m[i][j] * m[j][i];
    }
  }
  cout << r << endl;
}
