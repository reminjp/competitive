#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;

  ll a = 0;
  for (int i = 0, l = 0, r = 0; i < s.size(); i++) {
    if (s[i] == '<') {
      l++;
    } else if (s[i] == '>') {
      r++;
    }

    if (i + 1 == s.size() || s[i] == '>' && s[i + 1] == '<') {
      for (int i = 0; i < l; i++) a += i;
      for (int i = 0; i < r; i++) a += i;
      a += max(l, r);
      l = 0;
      r = 0;
    }
  }
  cout << a << endl;
}
