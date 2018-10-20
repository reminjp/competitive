#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int k;
  cin >> s >> k;
  set<string> t;
  for (int i = 0; i < s.size(); i++) {
    for (int j = 1; j <= k; j++) {
      t.insert(s.substr(i, j));
    }
  }
  vector<string> v;
  for (auto e : t) {
    v.push_back(e);
  }
  cout << v[k - 1] << endl;
  return 0;
}
