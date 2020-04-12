#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;

  ll r = 0, g = 0, b = 0;
  for (auto e : s) {
    if (e == 'R') {
      r++;
    } else if (e == 'G') {
      g++;
    } else if (e == 'B') {
      b++;
    }
  }

  ll m = r * g * b;
  for (int i = 0; i < n; i++) {
    for (int j = 1; i + 2 * j < n; j++) {
      if (s[i] != s[i + j] && s[i + j] != s[i + 2 * j] && s[i + 2 * j] != s[i]) m--;
    }
  }
  cout << m << endl;
}
