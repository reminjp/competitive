#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool r = false;
  for (auto e : s) r |= e == '7';
  cout << (r ? "Yes" : "No") << endl;
}
