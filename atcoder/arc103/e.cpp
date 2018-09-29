#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  bool is_possible = s[0] == '1' && s[s.size() - 1] == '0';
  for (int i = 1; i <= s.size() / 2; i++) {
    is_possible &= s[i - 1] == s[s.size() - i - 1];
  }
  if (!is_possible) {
    cout << -1 << endl;
    return 0;
  }

  vector<pair<int, int>> r;
  int t = 1;
  for (int i = 2; i <= s.size(); i++) {
    r.push_back({t, i});
    if (s[i - 2] == '1') {
      t = i;
    }
  }
  for (auto e : r) {
    cout << e.first << " " << e.second << endl;
  }
}
