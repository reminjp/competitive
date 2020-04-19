#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> r(n);
  for (int i = 1; i < n; i++) {
    int e;
    cin >> e;
    r[e - 1]++;
  }
  for (auto e : r) cout << e << endl;
}
