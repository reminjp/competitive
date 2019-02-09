#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  string r;
  int c = false;
  for (int i = 0; i < s.size() || i < t.size(); i++) {
    int x = i < s.size() && *(rbegin(s) + i) == 'B';
    int y = i < t.size() && *(rbegin(t) + i) == 'B';
    r.push_back("bB"[(c + x + y) % 2]);
    c = (c + x + y) / 2;
  }
  if (c) r.push_back("bB"[c]);
  if (r.empty()) r.push_back('b');
  reverse(begin(r), end(r));
  cout << r << endl;
}
