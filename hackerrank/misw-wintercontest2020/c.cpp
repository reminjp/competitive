#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  vector<ll> s{0};
  {
    constexpr int N = 1e5;
    s.reserve(N + 1);
    vector<bool> is_prime(100 * N + 1, true);
    for (int i = 2; i < is_prime.size() && s.size() < N + 1; i++) {
      if (!is_prime[i]) continue;
      s.push_back(i);
      for (int j = 2 * i; j < is_prime.size(); j += i) is_prime[j] = false;
    }
  }
  for (int i = 0; i + 1 < s.size(); i++) s[i + 1] += s[i];

  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << s[b] - s[a - 1] << endl;
  }
}
