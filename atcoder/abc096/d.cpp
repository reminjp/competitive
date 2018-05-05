#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<bool> p(1e5, true);
  for (int i = 2; i < 1e5; i++) {
    if (p[i]) {
      for (int j = 2 * i; j < 1e5; j += i) {
        p[j] = false;
      }
    }
  }
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 11; a.size() < n && i < 1e5; i += 10) {
    if (p[i]) {
      a.push_back(i);
    }
  }
  for (auto e : a) {
    cout << e << " ";
  }
  cout << endl;
  return 0;
}
