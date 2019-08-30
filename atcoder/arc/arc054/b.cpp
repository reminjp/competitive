#include <bits/stdc++.h>
using namespace std;

int main() {
  double p;
  cin >> p;
  auto f = [p](double x) { return x + p / pow(2.0, x / 1.5); };
  double bot = 0.0, top = 1e18, mid1, mid2;
  while (abs(top - bot) > 1e-9) {
    mid1 = (2.0 * bot + top) / 3.0;
    mid2 = (bot + 2.0 * top) / 3.0;
    if (f(mid1) > f(mid2)) {
      bot = mid1;
    } else {
      top = mid2;
    }
  }
  cout << fixed << setprecision(9);
  cout << f(bot) << endl;
}
