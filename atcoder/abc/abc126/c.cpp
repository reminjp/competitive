#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  double r = 0;
  for (int i = 1; i <= n; i++) {
    int j = 0;
    for (int d = i; d < k; d *= 2) j++;
    r += pow(0.5, j);
  }
  r /= n;
  cout << fixed << setprecision(9);
  cout << r << endl;
}
