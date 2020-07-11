#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string x;
  cin >> n >> x;

  vector<int> r(2), p(2);
  for (auto e : x) p[0] += e == '1';
  p[0]++;
  p[1] = p[0] - 2;
  for (auto e : x) {
    for (int i = 0; i < 2; i++) {
      if (p[i] == 0) continue;
      r[i] <<= 1;
      r[i] += e == '1';
      r[i] %= p[i];
    }
  }

  vector<vector<int>> br(2, vector<int>(n));
  for (int i = 0; i < 2; i++) {
    if (p[i] == 0) continue;
    br[i][0] = 1 % p[i];
    for (int j = 1; j < n; j++) br[i][j] = (br[i][j - 1] << 1) % p[i];
  }
  if (p[1] != 0) {
    for (int j = 0; j < n; j++) br[1][j] = (p[1] - br[1][j]) % p[1];
  }

  vector<int> m(n + 1);
  for (int i = 1; i <= n; i++) {
    int b = bitset<30>(i).count();
    m[i] = m[i % b] + 1;
  }

  for (int i = 0; i < n; i++) {
    int e = x[i] == '1';
    // cerr << r[e] << ' ' << br[e][n - 1 - i] << ' ' << (r[e] + br[e][n - 1 - i]) % p[e] << endl;
    cout << (p[e] == 0 ? 0 : m[(r[e] + br[e][n - 1 - i]) % p[e]] + 1) << endl;
  }
}
