#include <bits/stdc++.h>
using namespace std;

int main() {
  int w, k, d;
  cin >> w >> k >> d;
  cout << (k <= d && w - k <= d ? "Yes" : "No") << endl;
}
