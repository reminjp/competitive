#include <bits/stdc++.h>
using namespace std;
constexpr int M = 2e5;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n), b(n);
  vector<map<int, int>> v(M);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    b[i]--;
    v[b[i]][a[i]]++;
  }
  map<int, int> m;
  for (auto ve : v) {
    if (!ve.empty()) m[ve.rbegin()->first]++;
  }

  while (q--) {
    int c, d;
    cin >> c >> d;
    c--;
    d--;

    if (v[d].empty()) {
      m[a[c]]++;
    } else if (a[c] > v[d].rbegin()->first) {
      int k1 = v[d].rbegin()->first, k2 = a[c];
      m[k1]--;
      m[k2]++;
      if (m[k1] == 0) m.erase(k1);
    }

    v[b[c]][a[c]]--;
    v[d][a[c]]++;
    if (v[b[c]][a[c]] == 0) v[b[c]].erase(a[c]);

    if (v[b[c]].empty()) {
      m[a[c]]--;
      if (m[a[c]] == 0) m.erase(a[c]);
    } else if (a[c] > v[b[c]].rbegin()->first) {
      int k1 = a[c], k2 = v[b[c]].rbegin()->first;
      m[k1]--;
      m[k2]++;
      if (m[k1] == 0) m.erase(k1);
    }

    b[c] = d;

    cout << m.begin()->first << endl;
  }
}
