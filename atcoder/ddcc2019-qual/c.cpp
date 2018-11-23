#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = (int)1e9 + 7;

int main() {
  vector<vector<int>> c(11, vector<int>(11));
  for (int i = 0; i <= 10; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
  }

  int n;
  cin >> n;
  vector<ll> v(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 9; j++) {
      ll e = c[10][j];
      for (int k = 0; k < j; k++) {
        e = (e * (i - 1)) % mod;
      }
      v[i] = (v[i] + e) % mod;
    }
  }
  for (int i = 0; i < n; i++) {
    v[i + 1] = (v[i] + v[i + 1]) % mod;
  }

  ll r = 0;
  for (int p = 1; p <= n; p++) {
    int q = n / p;
    r = (r + ((mod + v[p] - v[p - 1]) % mod) * v[q] % mod) % mod;
  }
  cout << r << endl;
}
