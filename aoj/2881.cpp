#include <bits/stdc++.h>
using namespace std;

int main() {
  string g;
  while (cin >> g, g != "#") {
    int y, m, d;
    cin >> y >> m >> d;
    if (y > 31 || y == 31 && m >= 5) {
      cout << "? " << y - 30 << " " << m << " " << d << endl;
    } else {
      cout << g << " " << y << " " << m << " " << d << endl;
    }
  }
}
