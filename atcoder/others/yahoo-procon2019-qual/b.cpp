#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v(4);
  for (int i = 0; i < 3; i++) {
    int a, b;
    cin >> a >> b;
    v[a - 1]++;
    v[b - 1]++;
  }
  int r = 0;
  for (auto e : v) {
    r += e % 2;
  }
  cout << (r == 0 || r == 2 ? "YES" : "NO") << endl;
}
