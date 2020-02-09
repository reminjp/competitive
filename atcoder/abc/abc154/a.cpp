#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t, u;
  int a, b;
  cin >> s >> t >> a >> b >> u;
  cout << a - (s == u) << ' ' << b - (t == u) << endl;
}
