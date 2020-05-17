#include <bits/stdc++.h>
using namespace std;
static const double PI = std::acos(-1.0);

int main() {
  double a, b, h, m;
  cin >> a >> b >> h >> m;
  auto u = polar(a, 2 * PI * ((h + m / 60) / 12));
  auto v = polar(b, 2 * PI * (m / 60));
  cout << fixed << setprecision(10);
  cout << abs(v - u) << endl;
}
