#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  for (auto& e : s) {
    if (e == '?') e = 'D';
  }
  cout << s << endl;
}
