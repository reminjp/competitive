#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  bool r = false;
  for (int i = 0; i < s.size(); i++) {
    r |= s.substr(i) + s.substr(0, i) == t;
  }
  cout << (r ? "Yes" : "No") << endl;
}
