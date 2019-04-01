#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  string r;
  int p = 0;
  for (auto e : s) {
    if ('A' <= e && e <= 'Z') {
      if (e != 'A' + p) {
        r.push_back('A' + p);
      }
      p = (e - 'A' + 1) % 26;
    } else {
      r.push_back(e);
    }
  }
  cout << r << endl;
}
