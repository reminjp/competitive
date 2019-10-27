#include <bits/stdc++.h>
using namespace std;
constexpr double EPS = 1e-7;

int main() {
  double a, b, x;
  cin >> a >> b >> x;
  x /= a;
  double bot = 0, top = 90, mid;
  while (top - bot > EPS) {
    mid = (bot + top) / 2;
    double t = a * tan(mid / 180 * M_PI);
    double s = t <= b ? a * b - a * t / 2 : b * (b * tan((90 - mid) / 180 * M_PI)) / 2;
    if (s < x) {
      top = mid;
    } else {
      bot = mid;
    }
  }
  cout << fixed << setprecision(7);
  cout << bot << endl;
}
