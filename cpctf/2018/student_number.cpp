#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string y, x;
    cin >> y >> x;
    vector<int> v;
    for (auto e : y + x) {
      v.push_back(e - '0');
    }
    int s = 0;
    for (int i = 0; i < v.size() - 1; i++) {
      s += v[i] * (2 + i);
    }
    cout << (s % 11 % 10 == v.back() ? "YES" : "NO") << endl;
  }
  return 0;
}
