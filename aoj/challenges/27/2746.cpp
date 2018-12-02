#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  while (cin >> s, s != "#") {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<vector<char>> m;
    vector<char> t;
    for (auto e : s) {
      if (e == '/') {
        m.push_back(t);
        t.clear();
      } else if (e == 'b') {
        t.push_back('b');
      } else {
        for (int i = 0; i < e - '0'; i++) t.push_back('.');
      }
    }
    m.push_back(t);
    m[a - 1][b - 1] = '.';
    m[c - 1][d - 1] = 'b';
    string r;
    for (auto l : m) {
      for (auto e : l) {
        if (e == 'b') {
          r.push_back('b');
        } else if ('0' < r.back() && r.back() <= '9') {
          (*r.rbegin())++;
        } else {
          r.push_back('1');
        }
      }
      r.push_back('/');
    }
    r.pop_back();
    cout << r << endl;
  }
}
