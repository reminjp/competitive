#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

  vector<vector<bitset<27>>> v;
  for (const auto& e : s) {
    vector<bitset<27>> ve(e.size() + 1);
    for (int i = e.size() - 1; i >= 0; i--) {
      ve[i][e[i] - '`'] = true;
      ve[i] |= ve[i + 1];
    }
    v.push_back(ve);

    // cerr << e << endl;
  }

  ll r = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int ni = s[i].size(), nj = s[j].size();
      if (!(ni <= nj && s[i].substr(0, ni - 2) == s[j].substr(0, ni - 2))) break;
      if (v[j][ni - 2][s[i].back() - '`']) {
        r++;
        // cerr << s[i] << ' ' << s[j] << endl;
      }
    }
  }
  cout << r << endl;
}
