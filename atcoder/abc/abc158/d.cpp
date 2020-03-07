#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int q;
  cin >> s >> q;

  bool reversed = false;
  array<string, 2> pushed_chars;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      reversed = !reversed;
    } else {
      int f;
      char c;
      cin >> f >> c;
      pushed_chars[(f == 1) == reversed].push_back(c);
    }
  }

  reverse(pushed_chars.front().begin(), pushed_chars.front().end());
  s = pushed_chars.front() + s + pushed_chars.back();
  if (reversed) reverse(s.begin(), s.end());
  cout << s << endl;
}
