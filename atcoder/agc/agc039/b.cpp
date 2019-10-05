#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> v(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      if (s[j] == '1') v[i].push_back(j);
    }
  }

  int r = 0;
  for (int start = 0; start < n; start++) {
    bool b = true;
    vector<int> d(n, -1);
    queue<int> q;
    q.push(start);
    d[start] = 0;
    while (b && !q.empty()) {
      int i = q.front();
      q.pop();
      for (auto j : v[i]) {
        if (d[j] == -1) {
          d[j] = d[i] + 1;
          q.push(j);
        } else if (d[j] != d[i] - 1 && d[j] != d[i] + 1) {
          b = false;
          break;
        }
      }
    }
    if (b) r = max(r, *max_element(d.begin(), d.end()) + 1);
  }
  cout << (r ? r : -1) << endl;
}
