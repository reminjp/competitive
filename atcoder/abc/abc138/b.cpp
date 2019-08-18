#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  double r = 0;
  for (; n > 0; n--) {
    int a;
    cin >> a;
    r += 1.0 / a;
  }
  cout << fixed << setprecision(6) << 1.0 / r << endl;
}
