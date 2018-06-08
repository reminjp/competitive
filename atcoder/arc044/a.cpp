#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  bool r = n == 2 || n == 3 || n == 5 || n != 1 && n % 2 != 0 && n % 3 != 0 && n % 5 != 0;
  cout << (r ? "Prime" : "Not Prime") << endl;
}
