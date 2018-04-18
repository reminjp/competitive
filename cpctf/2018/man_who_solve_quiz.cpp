#include <bits/stdc++.h>
using namespace std;

int main() {
  static int d[] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
  int k;
  string s;
  cin >> k >> s;
  int n = 0;
  for (auto e : s) {
    n += d[e - '0'];
  }
  cout << n << endl;
  return 0;
}
