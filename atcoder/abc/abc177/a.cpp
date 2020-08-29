#include <bits/stdc++.h>
using namespace std;

int main() {
  int d, t, s;
  cin >> d >> t >> s;
  cout << ((d - 1) / s + 1 <= t ? "Yes" : "No") << endl;
}
