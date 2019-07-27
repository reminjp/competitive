#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 1e9 + 7;
constexpr int d = 13;

int main() {
  string s;
  cin >> s;
  vector<int> r(d);
  r[0] = 1;
  for (auto e : s) {
    vector<int> t(d);
    for (int j = 0; j < 10; j++) {
      if (e != '?' && e != '0' + j) continue;
      for (int k = 0; k < d; k++) {
        (t[(10 * k + j) % 13] += r[k]) %= mod;
      }
    }
    r = t;
  }
  cout << r[5] << endl;
}
