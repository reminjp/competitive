#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool r = true;
  for (int i = 0, n = s.size(); i < n / 2; i++) {
    r &= s[i] == s[n - 1 - i];
  }
  cout << (r ? "YES" : "NO") << endl;
}
