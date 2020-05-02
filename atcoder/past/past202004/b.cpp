#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  map<char, int> m;
  for (auto e : s) m[e]++;
  char r;
  int c = 0;
  for (auto e : m) {
    if (e.second > c) {
      r = e.first;
      c = e.second;
    }
  }
  cout << r << endl;
  ;
}
