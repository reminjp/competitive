#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b, c, d;
  string s;
  cin >> n >> a >> b >> c >> d >> s;
  vector<int> v(n, 1);
  for (int i = 1; i < n; i++) {
    if (s[i - 1] == s[i]) v[i] = v[i - 1] + 1;
  }
  bool r = true;
  for (int i = min(a, b) - 1; i < max(c, d); i++) {
    r &= !(s[i] == '#' && v[i] > 1);
  }
  if (b < c && d < c) {
    bool t = false;
    for (int i = b - 1 + 1; i < d + 1; i++) {
      t |= s[i] == '.' && v[i] >= 3;
    }
    r &= t;
  }
  cout << (r ? "Yes" : "No") << endl;
}
