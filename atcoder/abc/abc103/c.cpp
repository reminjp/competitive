#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int r = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    r += a - 1;
  }
  cout << r << endl;
}
