#include <bits/stdc++.h>
using namespace std;

template <class T>
class Prime {
 private:
  using S = typename std::vector<T>::size_type;
  std::vector<T> mind, primes;

 public:
  Prime(T n) : mind(n + 1) {
    mind[0] = mind[1] = 1;
    for (T i = 2; i < n; i++) {
      if (mind[i] == 0) primes.push_back(mind[i] = i);
      for (auto p : primes) {
        if (!(p <= mind[i] && i * p < n)) break;
        mind[i * p] = p;
      }
    }
  }
  bool operator()(T a) const { return a >= 2 && mind[a] == a; }
  T operator[](S i) const { return primes[i]; }
  S count() const { return primes.size(); }
};

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  Prime<int> prime(1e3);

  vector<int> v(1e6 + 1);
  int d = a.front();
  for (auto e : a) {
    d = gcd(d, e);
    for (int i = 0; i < prime.count() && prime[i] <= e; i++) {
      if (e % prime[i] != 0) continue;
      while (e % prime[i] == 0) e /= prime[i];
      v[i]++;
    }
    if (e > 1) v[e]++;
  }

  if (*max_element(v.begin(), v.end()) <= 1) {
    cout << "pairwise coprime" << endl;
  } else if (d == 1) {
    cout << "setwise coprime" << endl;
  } else {
    cout << "not coprime" << endl;
  }
}
