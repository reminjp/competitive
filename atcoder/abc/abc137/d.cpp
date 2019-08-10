#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(m + 1);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a <= m) v[a].push_back(b);
  }

  int r = 0;
  priority_queue<int> q;
  for (int i = 1; i <= m; i++) {
    for (auto e : v[i]) q.push(e);
    if (!q.empty()) {
      r += q.top();
      q.pop();
    }
  }
  cout << r << endl;
}
