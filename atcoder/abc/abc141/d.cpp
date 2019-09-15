#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  priority_queue<double> q;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    q.push(e);
  }
  for (int i = 0; i < m; i++) {
    auto e = q.top();
    q.pop();
    q.push(e / 2);
  }
  ll r = 0;
  while (!q.empty()) {
    r += int(q.top());
    q.pop();
  }
  cout << r << endl;
}
