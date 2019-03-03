#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<int> a(2);
  for (auto e : s) {
    a[e == '0']++;
  }
  cout << 2 * min(a[0], a[1]) << endl;
}
