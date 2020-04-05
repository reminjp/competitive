#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<tuple<int, int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> get<0>(a[i]) >> get<1>(a[i]);
    get<2>(a[i]) = i;
  }
  sort(a.begin(), a.end());

  string r(n, '.');
  int c = 0, j = 0;
  for (const auto& e : a) {
    if (c <= get<0>(e)) {
      r[get<2>(e)] = 'C';
      c = get<1>(e);
    } else if (j <= get<0>(e)) {
      r[get<2>(e)] = 'J';
      j = get<1>(e);
    } else {
      r = "IMPOSSIBLE";
      break;
    }
  }
  cout << r << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
