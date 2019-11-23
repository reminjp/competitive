#include <bits/stdc++.h>
using namespace std;

int main() {
  map<int, int> m;
  m[1] = 300000;
  m[2] = 200000;
  m[3] = 100000;
  int x, y;
  cin >> x >> y;
  cout << m[x] + m[y] + (x == 1 && y == 1 ? 400000 : 0) << endl;
}
