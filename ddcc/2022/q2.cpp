#include <bits/stdc++.h>
using namespace std;

int main() {
  string SABA = "SABA";
  string KOBONE = "kobone";

  int T = 3;
  while (T--) {
    string s;
    cin >> s;
    int n = s.size();

    vector<pair<int, int>> v;
    {
      int k = 0;
      for (int i = 0; i < n; i++) {
        if (s[i] == SABA[k]) {
          if (k == 0) {
            v.push_back({i, 0});
          }
          k++;
          if (k == SABA.size()) {
            v.back().second = i + 1;
            k = 0;
          }
        }
      }
    }
    // for (auto e : v) cerr << e.first << ", " << e.second << endl;

    vector<int> u;
    for (auto ve : v) {
      int k = 0;
      for (int i = ve.first; i < ve.second; i++) {
        if (s[i] == KOBONE[k]) {
          u.push_back(i);
          k++;
          if (k == KOBONE.size()) k = 0;
        }
      }
      u.resize(u.size() / KOBONE.size() * KOBONE.size());
      // for (auto e : u) cerr << e << ' ';
      // cerr << endl;
    }

    set<int> us(u.begin(), u.end());

    string r;
    for (int i = 0; i < n; i++) {
      if (!us.count(i)) r.push_back(s[i]);
    }

    cout << '"' << r << '"';
    if (T) cout << ',';
  }
  cout << endl;
}
