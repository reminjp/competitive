#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main() {
  int n, k;
  cin >> n >> k;
  vector<mint> a(n);
  for (auto &e : a) {
    int i;
    cin >> i;
    e = i;
  }

  vector c(k + 1, vector<mint>(k + 1));
  for (int i = 0; i <= k; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }

  vector<mint> s(k + 1);
  for (auto e : a) {
    mint p = 1;
    for (int j = 0; j <= k; j++, p *= e) s[j] += p;
  }

  for (int x = 1; x <= k; x++) {
    mint r;
    for (int j = 0; j <= x; j++) r += c[x][j] * (s[x - j] * s[j] - s[x]) / 2;
    cout << r.val() << endl;
  }
}
