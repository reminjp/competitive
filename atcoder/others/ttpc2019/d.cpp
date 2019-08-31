#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> p(1e6 + 1, true);
  p[0] = p[1] = false;
  for (int i = 2; i < p.size(); i++) {
    if (!p[i]) continue;
    for (int j = 2 * i; j < p.size(); j += i) p[j] = false;
  }
  vector<int> v = p;
  for (int i = 2; i < v.size(); i++) {
    if (v[i]) v[i] += v[i - 2];
  }

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) {
    int t;
    cin >> t;
    e = v[t];
  }

  int x = 0;
  for (auto e : a) x ^= e;
  cout << (x == 0 ? "Ai" : "An") << endl;
}
