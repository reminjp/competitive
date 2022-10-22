#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& e : a) cin >> e;

  ll r = 0;
  stack<ll> s;
  for (int i = 0; i < n;) {
    auto e = a[i];
    if (s.empty()) {
      if (e == 1) {
        s.push(e);
      } else {
        r += e;
      }
      i++;
    } else {
      auto t = s.top();
      if (e == 1) {
        s.push(e);
        i++;
      } else if (e == t + 1) {
        s.top() = e;
        i++;
      } else {
        s.pop();
      }
    }
  }

  cout << r << endl;
}
