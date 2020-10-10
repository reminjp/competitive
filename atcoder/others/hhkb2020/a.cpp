#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  cout << char(t.front() + (s.front() == 'Y' ? 'A' - 'a' : 0)) << endl;
}
