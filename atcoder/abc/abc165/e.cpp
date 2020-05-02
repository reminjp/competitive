#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a = i + 1, b = n - i;
    if (n % 2 == 0) {
      if (b - a <= n / 2) b--;
    }
    cout << a << ' ' << b << endl;
  }
}
