#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> a(3);
  for (auto &e : a) {
    cin >> e;
  }
  int r = 0;
  for (int i = 0; i < n; i++) {
    set<char> s;
    for (auto &e : a) {
      s.insert(e[i]);
    }
    r += (int)s.size() - 1;
  }
  cout << r << endl;
}
