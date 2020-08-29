#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  int r = 1e9;
  for (int i = 0; i + t.size() <= s.size(); i++) {
    int ri = 0;
    for (int j = 0; j < t.size(); j++) {
      if (s[i + j] != t[j]) ri++;
    }
    r = min(r, ri);
  }
  cout << r << endl;
}
