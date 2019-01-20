#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin >> a;
  set<int> s;
  int m = -1;
  for (int i = 1; i <= 1000000; i++) {
    if (s.count(a)) {
      m = i;
      break;
    }
    s.insert(a);
    a = a % 2 ? 3 * a + 1 : a / 2;
  }
  cout << m << endl;
}
