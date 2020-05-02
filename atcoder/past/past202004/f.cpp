#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto& e : a) {
    cin >> e.first >> e.second;
    e.first--;
  }
  a.push_back({n, 0});
  sort(a.begin(), a.end());

  int s = 0;
  priority_queue<int> q;
  for (int i = 0, k = 0; i < n + 1; i++) {
    while (k < a[i].first) {
      k++;
      s += q.top();
      q.pop();
      cout << s << '\n';
    }
    q.push(a[i].second);
  }
  cout << flush;
}
