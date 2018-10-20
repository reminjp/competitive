#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &e : a) {
    cin >> e;
  }
  vector<int> v = {1};
  for (int i = 1; i < n; i++) {
    if (a[i - 1] == a[i]) {
      (*rbegin(v))++;
    } else {
      v.push_back(1);
    }
  }
  int r = 0;
  for (auto e : v) {
    r += e / 2;
  }
  cout << r << endl;
}
