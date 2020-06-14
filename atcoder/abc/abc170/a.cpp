#include <bits/stdc++.h>
using namespace std;

int main() {
  int r = 0;
  for (int i = 1; i <= 5; i++) {
    int e;
    cin >> e;
    if (e == 0) r = i;
  }
  cout << r << endl;
}
