#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int c = 0;
  for (auto e : s) c += e == 'x';
  cout << (c < 8 ? "YES" : "NO") << endl;
}
