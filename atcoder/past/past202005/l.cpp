#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<deque<int>> t(n);
  for (auto& te : t) {
    int k;
    cin >> k;
    while (k--) {
      int e;
      cin >> e;
      te.push_back(e);
    }
  }

  vector<set<pair<int, int>>> s(2);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < s.size() && j < t[i].size(); j++) {
      s[j].insert({t[i][j], i});
    }
  }

  int m;
  cin >> m;
  while (m--) {
    int a;
    cin >> a;

    int emax = 0, imax, jmax;
    for (int j = 0; j < a; j++) {
      if (s[j].empty()) break;
      auto [e, i] = *s[j].rbegin();
      if (e > emax) {
        emax = e;
        imax = i;
        jmax = j;
      }
    }
    cout << emax << endl;

    for (int j = 0; j < s.size() && j < t[imax].size(); j++) {
      s[j].erase({t[imax][j], imax});
    }
    if (jmax == 0) {
      t[imax].pop_front();
    } else if (jmax == 1) {
      int e = t[imax].front();
      t[imax].pop_front();
      t[imax].front() = e;
    }
    for (int j = 0; j < s.size() && j < t[imax].size(); j++) {
      s[j].insert({t[imax][j], imax});
    }
  }
}
