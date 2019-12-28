#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  cout << (b - a) / 2 + (b - a) % 2 * min(a, n - b + 1) << endl;
}
