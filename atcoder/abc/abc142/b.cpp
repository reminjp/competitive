#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int r = 0;
  for (; n > 0; n--) {
    int h;
    cin >> h;
    r += h >= k;
  }
  cout << r << endl;
}
