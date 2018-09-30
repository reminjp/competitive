#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cout << "? " << (int)1e9 << endl;
  cin >> s;
  int is_odd = s.front() == 'o';
  int l = 1, r = (int)1e9 + 1, m;
  while (l + 2 < r) {
    m = (l + r) / 2;
    m += m % 2 == 0;
    cout << "? " << m << endl;
    cin >> s;
    if ((s.front() == 'o') == is_odd) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << "! " << l + !is_odd << endl;
}
