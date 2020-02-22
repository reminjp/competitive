#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int r = 0;
  for (; n; n /= k) r++;
  cout << r << endl;
}
