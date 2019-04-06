#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(5);
  for (auto &e : a) {
    cin >> e;
  }
  ll b = a.front();
  for (auto e : a) {
    b = min(b, e);
  }
  cout << 5 + (n - 1) / b << endl;
}
