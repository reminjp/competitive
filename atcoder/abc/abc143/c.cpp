#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int r = 1;
  for (int i = 1; i < n; i++) r += s[i - 1] != s[i];
  cout << r << endl;
}
