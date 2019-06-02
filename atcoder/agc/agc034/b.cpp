#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s, t;
  cin >> t;
  for (auto e : t) {
    if (e == 'A' || e == 'B') {
      s.push_back(e);
    } else if (e == 'C') {
      if (!s.empty() && s.back() == 'B') {
        *rbegin(s) = 'C';
      } else {
        s.push_back('.');
      }
    } else {
      s.push_back('.');
    }
  }
  ll r = 0, a = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A') {
      a++;
    } else if (s[i] == 'C') {
      r += a;
    } else {
      a = 0;
    }
  }
  cout << r << endl;
}
