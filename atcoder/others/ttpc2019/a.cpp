#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, t;
  cin >> a >> b >> t;
  cout << a + ((t - a - 1) / (b - a) + 1) * (b - a) << endl;
}
