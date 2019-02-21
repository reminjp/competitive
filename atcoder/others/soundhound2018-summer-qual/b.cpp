#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int w;
  cin >> s >> w;
  string t;
  for (int i = 0; i < s.size(); i += w) {
    t.push_back(s[i]);
  }
  cout << t << endl;
}
