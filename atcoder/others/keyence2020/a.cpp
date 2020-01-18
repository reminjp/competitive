#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  cout << (n - 1) / max(h, w) + 1 << endl;
}
