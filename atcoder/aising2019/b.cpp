#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int r0 = 0, r1 = 0, r2 = 0;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    if (p <= a) {
      r0++;
    } else if (p <= b) {
      r1++;
    } else {
      r2++;
    }
  }
  cout << min(r0, min(r1, r2)) << endl;
}
