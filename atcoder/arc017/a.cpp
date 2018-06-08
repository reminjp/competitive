#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  bool r = true;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      r = false;
      break;
    }
  }
  cout << (r ? "YES" : "NO") << endl;
}
