#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int r = 0;
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    r += a > m;
  }
  cout << r << endl;
}
