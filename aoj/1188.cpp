#include <bits/stdc++.h>
using namespace std;

string s;
int p;

int parse() {
  int m = 0;
  if (p < s.size()) {
    if (s[p] == '[') {
      vector<int> v;
      while (s[p] == '[') {
        p++;
        v.push_back(parse());
        p++;
      }
      sort(begin(v), end(v));
      for (int i = 0; i < v.size() / 2 + 1; i++) {
        m += v[i];
      }
    } else {
      while ('0' <= s[p] && s[p] <= '9') {
        m = 10 * m + int(s[p] - '0');
        p++;
      }
      m = m / 2 + 1;
    }
  }
  return m;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    p = 0;
    cout << parse() << endl;
  }
}
