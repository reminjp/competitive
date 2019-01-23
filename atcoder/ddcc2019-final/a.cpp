#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  double r = 0;
  int kmax = 0;
  for (int i = 0, k = 0; i < n; i++) {
    if (s[i] == '-') {
      r += 1.0;
      k = 0;
    } else {
      r += 1.0 / (k + 2);
      k++;
      kmax = max(kmax, k);
    }
  }
  r -= 1.0;
  r += 1.0 / (kmax + 2);
  cout << fixed << setprecision(8) << r << endl;
}
