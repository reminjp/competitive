#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int r = 0;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    if (i % 2 == 0 && e % 2 != 0) r++;
  }
  cout << r << endl;
}
