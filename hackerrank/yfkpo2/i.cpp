#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<priority_queue<int>> v(3);
  for (int i = 0; i < n; i++) {
    vector<int> a(3);
    for (auto &e : a) cin >> e;
    int k = -1;
    for (int j = 0; j < a.size(); j++) {
      if (a[j] > 1 || j == a.size() - 1) {
        v[j].push(-(a[j] - 1));
        break;
      }
    }
  }

  vector<int> p{10, 7, 7};
  int r = 0;
  vector<int> t(3, -k);
  for (; k > 0;) {
    bool lack = true;
    for (int i = 0; i < 3; i++) {
      while (k > 0 && !v[i].empty() && t[i] + v[i].top() >= 0) {
        t[i] += v[i].top();
        v[i].pop();
        k--;
        lack = false;
      }
    }
    if (lack) {
      r++;
      for (int i = 0; i < 3; i++) t[i] += p[i];
    }
  }
  cout << r << endl;
}
