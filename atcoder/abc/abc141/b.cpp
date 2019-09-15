#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool r = true;
  for (int i = 0; i < s.size(); i++) r &= !(i % 2 == 0 && s[i] == 'L') && !(i % 2 == 1 && s[i] == 'R');
  cout << (r ? "Yes" : "No") << endl;
}
