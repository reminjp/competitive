#include <bits/stdc++.h>
using namespace std;

int main() {
  int l;
  cin >> l;
  int n = 0;
  while (1 << n <= l) {
    n++;
  }

  vector<pair<pair<int, int>, int>> v;
  for (int i = 0; i < n - 1; i++) {
    v.push_back({{i, i + 1}, 0});
    v.push_back({{i, i + 1}, 1 << i});
  }
  for (int i = n - 2; i >= 0; i--) {
    if (1 << n - 1 <= l - (1 << i)) {
      v.push_back({{i, n - 1}, l - (1 << i)});
      l -= 1 << i;
    }
  }

  cout << n << " " << v.size() << endl;
  for (auto e : v) {
    cout << e.first.first + 1 << " " << e.first.second + 1 << " " << e.second << endl;
  }
}
