#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 1e9, D = 9;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& e : a) {
    string s;
    cin >> s;
    ll x = 0, y = 0, d = 0;
    bool b = false;
    for (auto c : s) {
      if (c == '.') {
        b = true;
      } else if (b) {
        y *= 10;
        y += c - '0';
        d++;
      } else {
        x *= 10;
        x += c - '0';
      }
    }
    e = x * N + y * (ll)pow(10, D - d);
    // cerr << x << ' ' << y << ' ' << d << ' ' << e << endl;
  }

  vector<vector<ll>> m(50, vector<ll>(50));
  for (auto e : a) {
    int i = 0, j = 0;
    for (; e % 2 == 0; e /= 2) i++;
    for (; e % 5 == 0; e /= 5) j++;
    m[i][j]++;
  }

  ll r = 0;
  for (int i1 = 0; i1 < 50; i1++) {
    for (int j1 = 0; j1 < 50; j1++) {
      for (int i2 = 0; i2 < 50; i2++) {
        if (i1 + i2 < 2 * D) continue;
        for (int j2 = 0; j2 < 50; j2++) {
          if (j1 + j2 < 2 * D) continue;
          if (i1 == i2 && j1 == j2) {
            r += m[i1][j1] * (m[i1][j1] - 1);
          } else {
            r += m[i1][j1] * m[i2][j2];
          }
        }
      }
    }
  }
  r /= 2;
  cout << r << endl;
}
