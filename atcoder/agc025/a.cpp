#include <bits/stdc++.h>
using namespace std;

int main() {
  string n;
  cin >> n;
  int s = 0;
  for (auto e : n) {
    s += e - '0';
  }
  cout << (s < 2 ? 10 * s : s) << endl;
  return 0;
}
