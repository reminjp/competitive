#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  n = n * (n + 1) / 2;
  bool r = n > 1;
  for (int i = 2; i * i <= n; i++) {
    r &= n % i != 0;
  }
  cout << (r ? "WANWAN" : "BOWWOW") << endl;
}
