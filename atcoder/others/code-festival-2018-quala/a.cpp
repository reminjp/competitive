#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, s;
  cin >> a >> b >> c >> s;
  int d = s - a - b - c;
  cout << (0 <= d && d <= 3 ? "Yes" : "No") << endl;
}
