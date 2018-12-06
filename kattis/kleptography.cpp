#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  string r = string(m - n, '.') + s;
  for (int i = m - n - 1; i >= 0; i--) {
    r[i] = 'a' + (26 + (t[i + n] - 'a') - (r[i + n] - 'a')) % 26;
  }
  cout << r << endl;
}
