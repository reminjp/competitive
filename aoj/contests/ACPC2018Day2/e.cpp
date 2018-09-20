#include <bits/stdc++.h>
using namespace std;

int main() {
  double W, H, w, h, x, y;
  cin >> W >> H >> w >> h >> x >> y;
  double a = x + w / 2 <= W / 2 ? x : W / 2 - (W / 2 - (x - w / 2)) / 2;
  double b = y + h / 2 <= H / 2 ? y : H / 2 - (H / 2 - (y - h / 2)) / 2;
  cout << fixed << setprecision(6) << b / a << endl;
}
