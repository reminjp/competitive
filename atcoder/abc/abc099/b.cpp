#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int h = -a;
  for (int i = 0; i < b - a; i++) {
    h += i;
  }
  cout << h << endl;
}
