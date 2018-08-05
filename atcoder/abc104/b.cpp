#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  cout << (regex_match(s, regex("A[a-z]+C[a-z]+")) ? "AC" : "WA") << endl;
}
