#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, n;
  cin >> a >> b >> c >> n;
  int s = 0;
  while (n--) {
    int e;
    cin >> e;
    s += e;
  }
  cout << (s <= 10000 * a + 5000 * b + 1000 * c ? "Yes" : "No") << endl;
}
