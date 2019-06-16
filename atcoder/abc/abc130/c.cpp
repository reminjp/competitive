#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 1e9 + 7;

int main() {
  long long w, h, x, y;
  cin >> w >> h >> x >> y;
  cout << fixed << setprecision(9);
  cout << w * h / 2.0 << ' ' << int(2 * x == w && 2 * y == h) << endl;
}
