#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  double r = 0;
  for (int i = 0; i < n; i++) {
    double x;
    string u;
    cin >> x >> u;
    if (u == "JPY") {
      r += x;
    } else if (u == "BTC") {
      r += 380000.0 * x;
    }
  }
  cout << fixed << setprecision(5) << r << endl;
}
