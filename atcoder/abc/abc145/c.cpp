#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

  vector<int> f(n + 1);
  f[0] = 1;
  for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i;

  double r = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      r += 2 * f[n - 1] * sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
    }
  }
  r /= f[n];
  cout << fixed << setprecision(7);
  cout << r << endl;
}
