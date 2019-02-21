#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> a(4);
  for (auto &e : a) {
    cin >> e;
  }
  sort(begin(a), end(a));
  cout << (a[0] == 1 && a[1] == 4 && a[2] == 7 && a[3] == 9 ? "YES" : "NO") << endl;
}
