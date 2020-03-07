#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  cout << n / (a + b) * a + min(a, n % (a + b)) << endl;
}
