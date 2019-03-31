#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int t = 0;
  for (auto e : s) t += e - '0';
  int n = s.size(), h = s.front() - '0', r = h + (n - 1) * 9;
  cout << r - (r != t) << endl;
}
