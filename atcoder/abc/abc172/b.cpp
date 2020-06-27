#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  int r = 0;
  for (int i = 0; i < s.size(); i++) r += s[i] != t[i];
  cout << r << endl;
}
