#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll a) {
  switch (a % 4) {
    case 0:
      return a;
    case 1:
      return 1;
    case 2:
      return a + 1;
    case 3:
      return 0;
  }
}

int main() {
  ll a, b;
  cin >> a >> b;
  cout << (f(a - 1) ^ f(b)) << endl;
}
