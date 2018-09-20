#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  int h = 0;
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    if (a) {
      h = (h + b) % n;
    } else {
      cout << (h + b - 1) % n + 1 << endl;
    }
  }
}
