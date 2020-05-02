#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  set<string> r;
  for (int i = 0; i < s.size(); i++) {
    for (int j = 1; j <= 3 && i + j <= s.size(); j++) {
      for (int b = 0; b < (1 << j); b++) {
        auto t = s.substr(i, j);
        for (int k = 0; k < j; k++) {
          if (b >> k & 1) t[k] = '.';
        }
        r.insert(t);
      }
    }
  }
  cout << r.size() << endl;
}
