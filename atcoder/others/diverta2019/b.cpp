#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  int a = 0;
  for (int i = 0; i * r <= n; i++) {
    for (int j = 0; i * r + j * g <= n; j++) {
      int k = n - (i * r + j * g);
      if (0 <= k && k % b == 0) a++;
    }
  }
  cout << a << endl;
}
