#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int r = 1e9;
  for (int i = 0; i < s.size() - 2; i++) {
    r = min(r, abs(100 * (s[i] - '0') + 10 * (s[i + 1] - '0') + (s[i + 2] - '0') - 753));
  }
  cout << r << endl;
}
