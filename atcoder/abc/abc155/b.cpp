#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  bool r = true;
  while (n--) {
    int a;
    cin >> a;
    r = r && (a % 2 != 0 || a % 3 == 0 || a % 5 == 0);
  }
  cout << (r ? "APPROVED" : "DENIED") << endl;
}
