#include <bits/stdc++.h>
using namespace std;

bool f(const string& s) {
  for (int i = 0; 2 * i < s.size(); i++) {
    if (s[i] != s[s.size() - 1 - i]) return false;
  }
  return true;
}

int main() {
  string s;
  cin >> s;
  int n = s.size();
  bool r = true;
  r = r && f(s);
  r = r && f(s.substr(0, (n - 1) / 2));
  r = r && f(s.substr((n + 3) / 2 - 1, n - ((n + 3) / 2) + 1));
  cout << (r ? "Yes" : "No") << endl;
}
