#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int k = 2540;
  int n, m;
  cin >> n >> m;
  vector<map<int, ll>> v(n);
  for (int i = 0; i < m; i++) {
    int a, b, l;
    cin >> a >> b >> l;
    v[a - 1][l]++;
    v[b - 1][l]++;
  }
  ll r = 0;
  for (auto vi : v) {
    for (auto e : vi) {
      r += 2 * e.first == k ? e.second * (e.second - 1) : e.second * vi[k - e.first];
    }
  }
  cout << r / 2 << endl;
}
