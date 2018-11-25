#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int r = 1;
  for (int h = 0, i = 1; i < s.size(); i++) {
    if (s[h] >= s[i]) {
      h = i;
      r++;
    }
  }
  cout << r << endl;
}
