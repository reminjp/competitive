#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> primes;
  {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
      if (is_prime[i]) {
        primes.push_back(i);
        for (int j = 2 * i; j <= n; j += i) {
          is_prime[j] = false;
        }
      }
    }
  }
  for (auto e : primes) cerr << e << " ";
  cerr << endl;

  vector<int> f(n + 1);
  for (int i = 1; i <= n; i++) {
    int t = i;
    for (auto e : primes) {
      for (; t % e == 0; t /= e) {
        f[e]++;
      }
    }
  }
  vector<int> s(accumulate(begin(f), end(f), 74, [](int a, int b) { return max(a, b); }) + 1);
  for (auto e : f) {
    s[e]++;
  }
  for (int i = s.size() - 1; i > 0; i--) {
    s[i - 1] += s[i];
  }

  int r = s[74];
  if (s[24] >= 1) r += s[24] * (s[2] - 1);
  if (s[14] >= 1) r += s[14] * (s[4] - 1);
  if (s[4] >= 2) r += s[4] * (s[4] - 1) / 2 * (s[2] - 2);
  cout << r << endl;
}
