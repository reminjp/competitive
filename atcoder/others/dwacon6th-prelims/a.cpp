#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  vector<int> t(n);
  for (int i = 0; i < n; i++) cin >> s[i] >> t[i];
  string x;
  cin >> x;

  int k;
  for (int i = 0; i < n; i++) {
    if (x == s[i]) k = i + 1;
  }
  int r = 0;
  for (int i = k; i < n; i++) r += t[i];
  cout << r << endl;
}
