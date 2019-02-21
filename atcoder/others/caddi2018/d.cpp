#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  bool r = false;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    r |= a % 2;
  }
  cout << (r ? "first" : "second") << endl;
}
