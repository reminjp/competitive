#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  ll manhattan = 0, euclidean = 0, chebyshev = 0;
  while (n--) {
    ll x;
    cin >> x;
    manhattan += abs(x);
    euclidean += x * x;
    chebyshev = max(chebyshev, abs(x));
  }
  cout << manhattan << endl;
  cout << fixed << setprecision(10) << sqrt(euclidean) << endl;
  cout << chebyshev << endl;
}
