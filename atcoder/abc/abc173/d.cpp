#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& e : a) cin >> e;
  sort(a.rbegin(), a.rend());

  ll r = 0;
  queue<ll> q;
  for (auto e : a) {
    if (!q.empty()) {
      r += q.front();
      q.pop();
      q.push(e);
    }
    q.push(e);
  }
  cout << r << endl;
}
