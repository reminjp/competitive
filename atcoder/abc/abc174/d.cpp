#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;

  auto t = s;
  sort(t.begin(), t.end());
  int r = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'W' && t[i] == 'R') r++;
  }
  cout << r << endl;
}
