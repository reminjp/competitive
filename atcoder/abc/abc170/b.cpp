#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  bool r = false;
  for (int i = 0; i <= x; i++) r = r || 2 * i + 4 * (x - i) == y;
  cout << (r ? "Yes" : "No") << endl;
}
