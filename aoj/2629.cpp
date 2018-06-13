#include <bits/stdc++.h>
using namespace std;

int main() {
  double d;
  cin >> d;
  cout << fixed << setprecision(9) << max(floor(d) + 1, 2 * sqrt(d * d / 2)) << endl;
  return 0;
}
