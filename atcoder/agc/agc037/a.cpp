#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int r = 0;
  string a, b;
  for (auto e : s) {
    b.push_back(e);
    if (a != b) {
      r++;
      a = b;
      b.clear();
    }
  }
  cout << r << endl;
}
