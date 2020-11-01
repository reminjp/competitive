#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  vector<int> c(10);
  for (auto e : s) c[e - '0']++;

  auto f = [&](auto&& f, int i, int s) {
    if (i == 0) {
      return s % 8 == 0;
    }
    if (i > 3) i = 3;
    bool r = false;
    for (int e = 0; e < 10 && !r; e++) {
      if (c[e] == 0) continue;
      c[e]--;
      r = r || f(f, i - 1, 10 * s + e);
      c[e]++;
    }
    return r;
  };
  cout << (f(f, s.size(), 0) ? "Yes" : "No") << endl;
}
