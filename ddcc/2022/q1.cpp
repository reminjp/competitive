#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<bool> is_prime(10000, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i < is_prime.size(); i++) {
    for (int j = 2 * i; j < is_prime.size(); j += i) is_prime[j] = false;
  }

  int T = 3;
  while (T--) {
    int n;
    cin >> n;

    int r = 0;
    for (int i = 1; i < n; i++) {
      if (!is_prime[i] || !is_prime[n - i]) continue;
      r = max(r, i * (n - i));
    }
    cout << r;
    if (T) cout << ',';
  }
  cout << endl;
}
