#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<set<char>> a(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    a[i] = set<char>(s.begin(), s.end());
  }

  bool valid = true;
  string r(n, '.');
  for (int i = 0; i <= n - 1 - i; i++) {
    for (auto e : a[i]) {
      if (a[n - 1 - i].count(e)) {
        r[i] = r[n - 1 - i] = e;
        break;
      }
    }
    if (r[i] == '.') {
      valid = false;
      break;
    }
  }

  if (valid) {
    cout << r << endl;
  } else {
    cout << -1 << endl;
  }
}
