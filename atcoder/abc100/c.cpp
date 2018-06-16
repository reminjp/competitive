#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int m = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    for (; a % 2 == 0; a /= 2) {
      m++;
    }
  }
  cout << m << endl;
  return 0;
}
