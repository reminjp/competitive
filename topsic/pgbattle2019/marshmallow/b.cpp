#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s;
  t = s;
  for (auto& e : t) {
    if ('A' <= e && e <= 'Z') e = e - 'A' + 'a';
  }
  if (s == "AtCoder") {
    cout << "Yes" << endl;
  } else if (t == "atcoder") {
    cout << "Maybe" << endl;
  } else {
    cout << "No" << endl;
  }
}
