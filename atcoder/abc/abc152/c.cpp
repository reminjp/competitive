#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    a[e - 1] = i;
  }
  int r = n;
  set<int> s;
  for (auto e : a) {
    if (!s.empty() && *s.begin() < e) r--;
    s.insert(e);
  }
  cout << r << endl;
}
