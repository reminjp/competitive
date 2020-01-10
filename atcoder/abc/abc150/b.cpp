#include <bits/stdc++.h>
using namespace std;

int main() {
  string t = "ABC";
  int n;
  string s;
  cin >> n >> s;
  int r = 0;
  for (int i = 0; i + t.size() - 1 < n; i++) {
    bool b = true;
    for (int j = 0; b && j < t.size(); j++) b = s[i + j] == t[j];
    if (b) r++;
  }
  cout << r << endl;
}
