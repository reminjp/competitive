#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll h, w;
  cin >> h >> w;
  cout << (h == 1 || w == 1 ? 1 : (h * w - 1) / 2 + 1) << endl;
}
