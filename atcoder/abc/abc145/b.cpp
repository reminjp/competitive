#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  bool r = n % 2 == 0;
  for (int i = 0; r && i < n / 2; i++) r &= s[i] == s[i + n / 2];
  cout << (r ? "Yes" : "No") << endl;
}
