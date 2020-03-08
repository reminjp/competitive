#include <bits/stdc++.h>
using namespace std;

int main() {
  string t = "hi";
  string s;
  cin >> s;
  bool r = s.size() % 2 == 0;
  for (int i = 0; i < s.size(); i++) r = r && s[i] == t[i % 2];
  cout << (r ? "Yes" : "No") << endl;
}
