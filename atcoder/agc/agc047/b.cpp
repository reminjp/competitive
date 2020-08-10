#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (auto& e : s) {
    cin >> e;
    reverse(e.begin(), e.end());
    e.insert(e.end() - 1, 'a' - 1);
  }
  sort(s.begin(), s.end());

  vector<vector<bitset<27>>> v(n);
  for (int i = 0; i < n; i++) {
    int l = s[i].size();
    v[i].resize(l + 1);
    for (int j = l - 1; j >= 0; j--) {
      v[i][j][s[i][j] - ('a' - 1)] = true;
      v[i][j] |= v[i][j + 1];
    }
  }

  int r = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int li = s[i].size(), lj = s[j].size();
      if (li > lj || s[i].substr(0, li - 2) != s[j].substr(0, li - 2)) break;
      if (v[j][li - 2][s[i].back() - ('a' - 1)]) r++;
    }
  }
  cout << r << endl;
}
