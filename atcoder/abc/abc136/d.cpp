#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();

  vector<int> r(n);
  for (int i = 0, t = 0; i + 1 < n; i++) {
    if (s[i] == 'R') {
      t++;
      if (s[i + 1] == 'L') {
        r[i] += (t + 1) / 2;
        r[i + 1] += t / 2;
        t = 0;
      }
    }
  }
  for (int i = n - 1, t = 0; i - 1 >= 0; i--) {
    if (s[i] == 'L') {
      t++;
      if (s[i - 1] == 'R') {
        r[i] += (t + 1) / 2;
        r[i - 1] += t / 2;
        t = 0;
      }
    }
  }

  for (auto e : r) cout << e << ' ';
  cout << endl;
}
