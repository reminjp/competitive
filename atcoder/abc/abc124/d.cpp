#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;

  vector<int> v = {0, 0};
  for (auto e : s) {
    if (e - '0' == (v.size() + 1) % 2) {
      (*rbegin(v))++;
    } else {
      v.push_back(1);
    }
  }
  v.push_back(0);
  for (int i = 0; i + 1 < v.size(); i++) {
    v[i + 1] += v[i];
  }

  int w = min((int)v.size() - 1, 2 * k + 1);
  int r = 0;
  for (int i = 0; i + w < v.size(); i += 2) {
    r = max(r, v[i + w] - v[i]);
  }
  cout << r << endl;
}
