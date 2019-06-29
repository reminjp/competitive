#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  map<char, int> m;
  for (auto e : s) m[e]++;
  bool r = true;
  for (auto e : m) r = r && e.second == 2;
  cout << (r ? "Yes" : "No") << endl;
}
