#include <bits/stdc++.h>
using namespace std;

int main() {
  string t = "keyence";
  string s;
  cin >> s;
  int a = 0, b = 0;
  while (a < s.size() && a < t.size() && s[a] == t[a]) a++;
  while (b < s.size() && b < t.size() && s[s.size() - 1 - b] == t[t.size() - 1 - b]) b++;
  cout << (a + b >= t.size() ? "YES" : "NO") << endl;
}
