#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll a, b, c, k;
  cin >> a >> b >> c >> k;
  int s = k % 2 ? -1 : 1;
  cout << s * a + -s * b << endl;
}
