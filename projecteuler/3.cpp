#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n = 600851475143;
  vector<ll> is_prime(int(sqrt(n)) + 1, true);
  int answer = 0;
  for (int i = 2; i < is_prime.size(); i++) {
    if (!is_prime[i]) continue;
    for (int j = 2 * i; j < is_prime.size(); j += i) is_prime[j] = false;
    if (n % i == 0) answer = i;
  }
  cout << answer << endl;
}
