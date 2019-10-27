#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool r = true;
  for (int i = 0; i < s.size() / 2; i++)
    r = r && (s[i] == s[s.size() - 1 - i] || s[i] == '*' || s[s.size() - 1 - i] == '*');
  cout << (r ? "YES" : "NO") << endl;
}
