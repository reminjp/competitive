#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  cout << (regex_match(s, regex(".*[iI].*[cC].*[tT].*")) ? "YES" : "NO") << endl;
}
