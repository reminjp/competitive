#include <bits/stdc++.h>
using namespace std;

int main() {
  int m, d;
  cin >> m >> d;
  int r = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 10; j <= d; j++) {
      r += j % 10 >= 2 && j / 10 >= 2 && (j % 10) * (j / 10) == i;
    }
  }
  cout << r << endl;
}
