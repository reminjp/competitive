#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  int r = 0, m = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    r += a * b;
    m = max(m, b);
  }
  r += x * m;
  cout << r << endl;
}
