#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  double r = 0;
  for (; n > 0; n--) {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    r = max(r, a + b + c + d + e * 110.0 / 900.0);
  }
  cout << fixed << setprecision(4) << r << endl;
}
