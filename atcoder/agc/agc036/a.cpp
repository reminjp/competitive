#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int m = 1e9;

int main() {
  ll s;
  cin >> s;
  int x1 = 0, y1 = 1;
  int x2 = m, y2 = 0;
  int x3 = (s - 1) % m + 1, y3 = (s - 1) / m + 1;
  cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3 << endl;
}
