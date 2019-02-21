#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int k = floor(sqrt(2 * n)) + 1;
  if ((k - 1) * k == 2 * n) {
    vector<vector<int>> a(k);
    for (int i = 0, e = 1; i < k; i++) {
      for (int j = i + 1; j < k; j++, e++) {
        a[i].push_back(e);
        a[j].push_back(e);
      }
    }
    cout << "Yes" << endl;
    cout << k << endl;
    for (auto s : a) {
      cout << s.size() << " ";
      for (auto e : s) {
        cout << e << " ";
      }
      cout << endl;
    }
  } else {
    cout << "No" << endl;
  }
}
