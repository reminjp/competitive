#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  cin >> k;

  set<int> s;
  int r = 1, x = 7;
  while (x % k) {
    r++;
    x = (10 * x + 7) % k;
    if (s.count(x)) {
      r = -1;
      break;
    }
    s.insert(x);
  }
  cout << r << endl;
}
