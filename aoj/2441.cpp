#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll length(ll n) {
  if (n == 0) {
    return 0;
  }
  ll k = 1, d = 1;
  while (10 * k <= n) {
    k *= 10;
    d++;
  }
  k--;
  ll n3 = n / 3 - k / 3;
  ll n5 = n / 5 - k / 5;
  ll n15 = n / 15 - k / 15;
  return length(k) + 4 * (n3 + n5) + d * (n - k - n3 - n5 + n15);
}

int main() {
  ll s;
  cin >> s;

  ll ok = 1, ng = 1e17, m;
  while (ng - ok > 1) {
    m = (ok + ng) / 2;
    ll l = length(m - 1);
    if (l <= s - 1) {
      ok = m;
    } else {
      ng = m;
    }
  }

  string r;
  for (ll i = ok; r.size() < 100; i++) {
    if (i % 15 == 0) {
      r += "FizzBuzz";
    } else if (i % 3 == 0) {
      r += "Fizz";
    } else if (i % 5 == 0) {
      r += "Buzz";
    } else {
      r += to_string(i);
    }
  }
  cout << r.substr(s - 1 - length(ok - 1), 20) << endl;
}
