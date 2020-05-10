#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<tuple<bool, int, int, int>> v(n);
  for (auto &e : v) {
    string s;
    cin >> s;
    int l = 0, r = 0;
    for (auto c : s) {
      if (c == '(') {
        l++;
      } else if (l > 0) {
        l--;
      } else {
        r++;
      }
    }
    e = {l <= r, l <= r ? -l : r, l, r};
  }
  sort(v.begin(), v.end());

  bool valid = true;
  int h = 0;
  for (auto [a, b, l, r] : v) {
    // cerr << a << ' ' << b << ' ' << r << ' ' << l << endl;
    if (h < r) {
      valid = false;
      break;
    }
    h -= r;
    h += l;
  }
  if (h != 0) valid = false;
  cout << (valid ? "Yes" : "No") << endl;
}
