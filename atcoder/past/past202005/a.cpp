#include <bits/stdc++.h>
using namespace std;

void ToLower(string &s) {
  for (auto &e : s) e = tolower(e);
}

int main() {
  string s, t;
  cin >> s >> t;
  if (s == t) {
    cout << "same" << endl;
    return 0;
  }
  ToLower(s);
  ToLower(t);
  if (s == t) {
    cout << "case-insensitive" << endl;
    return 0;
  }
  cout << "different" << endl;
}
