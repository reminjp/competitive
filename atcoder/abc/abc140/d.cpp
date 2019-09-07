#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  int x = 0;
  for (int i = 0; i + 1 < n; i++) x += s[i] == s[i + 1];
  cout << min(n - 1, x + 2 * k) << endl;
}
