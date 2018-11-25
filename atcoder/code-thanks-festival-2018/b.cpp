#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  int d = abs(x - y), m = min(x, y);
  cout << (d % 2 == 0 && m - d / 2 >= 0 && (m - d / 2) % 4 == 0 ? "Yes" : "No") << endl;
}
