#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  cout << (a < b ? string(b, '0' + a) : string(a, '0' + b)) << endl;
}
