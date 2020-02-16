#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<string, int> m;
  int c = 0;
  while (n--) {
    string e;
    cin >> e;
    m[e]++;
    c = max(c, m[e]);
  }
  set<string> s;
  for (const auto& e : m) {
    if (e.second == c) s.insert(e.first);
  }
  for (const auto& e : s) cout << e << endl;
}
