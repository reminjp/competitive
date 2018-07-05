#include <bits/stdc++.h>
using namespace std;

string s, t;
int p;

int parse() {
  int h;
  if (p < s.size()) {
    if (s[p] == '[') {
      p++;
      char op = s[p];
      p++;
      int h1 = parse(), h2 = parse();
      p++;
      if (op == '+') {
        h = h1 | h2;
      } else if (op == '*') {
        h = h1 & h2;
      } else if (op == '^') {
        h = h1 ^ h2;
      }
    } else {
      for (int i = 0; i < 4; i++) {
        if (s[p] == 'a' + i) {
          h = t[i] - '0';
          break;
        }
      }
      p++;
    }
  }
  return h;
}

int main() {
  int k;
  while (cin >> s >> k, s != ".") {
    vector<int> v(1e4);
    for (int i = 0; i < v.size(); i++) {
      t = ("000" + to_string(i));
      t = t.substr(t.size() - 4);
      p = 0;
      v[i] = parse();
    }
    int m = 0;
    for (int i = 0; i < v.size(); i++) {
      m += v[i] == v[k];
    }
    cout << v[k] << " " << m << endl;
  }
}
