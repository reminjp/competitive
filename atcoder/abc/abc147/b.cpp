#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int r = 0;
  for (int i = 0; i < s.size() / 2; i++) r += s[i] != s[s.size() - 1 - i];
  cout << r << endl;
}
