#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  t.pop_back();
  cout << (s == t ? "Yes" : "No") << endl;
}
