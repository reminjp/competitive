#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int r = 0;
  for (int i = 1; i < n; i++) r += (n - 1) / i;
  cout << r << endl;
}
