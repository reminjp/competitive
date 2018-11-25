#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, a, b, c, d;
  cin >> t >> a >> b >> c >> d;
  cout << (a + c <= t ? b + d : c <= t ? d : a <= t ? b : 0) << endl;
}
