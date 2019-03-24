#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int r = 0, t = 0;
  for (auto e : s) {
    if (e == 'A' || e == 'C' || e == 'G' || e == 'T') {
      t++;
      r = max(r, t);
    } else {
      t = 0;
    }
  }
  cout << r << endl;
}
