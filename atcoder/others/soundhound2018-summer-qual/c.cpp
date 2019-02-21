#include <bits/stdc++.h>
using namespace std;

int main() {
  double n, m, d;
  cin >> n >> m >> d;
  cout << fixed << setprecision(6) << (m - 1) * (d ? 2.0 * (n - d) / (n * n) : 1.0 / n) << endl;
}
