#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, b, f;
  cin >> n >> b >> f;
  vector<int> v(n - b);
  int m = 1 << f;
  for (f--; f >= 0; f--) {
    int e = 1 << f;
    string q, r;
    for (int i = 0; i < n; i++) q.push_back('0' + (i / e % 2));
    cout << q << endl;
    cin >> r;
    for (int i = 0; i < n - b; i++) v[i] += (r[i] - '0') * e;
  }
  {
    int k = 0;
    vector<int> v0 = v;
    for (int i = 1; i < n - b; i++) {
      if (v0[i - 1] > v0[i]) k++;
      v[i] += k * m;
    }
  }
  set<int> s(begin(v), end(v));
  for (int i = 0; i < n; i++) {
    if (!s.count(i)) cout << i << " ";
  }
  cout << endl;
  int verdict;
  cin >> verdict;
  if (verdict == -1) exit(0);
}

int main() {
  int t;
  cin >> t;
  for (; t > 0; t--) solve();
}
