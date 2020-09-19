#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int r = 0;
  for (int t = 0; n--;) {
    int a, b;
    cin >> a >> b;
    if (a == b) {
      t++;
    } else {
      t = 0;
    }
    r = max(r, t);
  }
  cout << (r >= 3 ? "Yes" : "No") << endl;
}
