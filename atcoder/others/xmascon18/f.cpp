#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> r;
  int a = 1e9, b = 1;
  for (int i = 0; i < n; i++) {
    r.push_back(vector<int>{0, a, b, 1, 0, a - 1, b, 0, 0, a - 2});
    a += -1e7;
    b += 1e7;
  }
  for (auto ri : r) {
    for (auto e : ri) {
      cout << e << " ";
    }
    cout << endl;
  }
}
