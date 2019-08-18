#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s, t;
  cin >> s >> t;
  vector<vector<int>> v(s.size(), vector<int>(1 << 8, -1));
  for (int _ = 0; _ < 2; _++) {
    for (int i = s.size() - 1; i >= 0; i--) {
      int j = (s.size() + i - 1) % s.size();
      v[j] = v[i];
      v[j][s[i]] = i;
    }
  }
  ll r = 0, p = 0;
  bool b = false;
  for (int i = s[0] == t[0]; i < t.size(); i++) {
    if (v[p][t[i]] == -1) {
      b = true;
      break;
    }
    if (v[p][t[i]] <= p) r++;
    p = v[p][t[i]];
  }
  cout << (b ? -1 : r * int(s.size()) + p + 1) << endl;
}
