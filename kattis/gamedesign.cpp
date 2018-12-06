#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
map<char, int> c2i = {{'U', 0}, {'R', 1}, {'D', 2}, {'L', 3}};

int main(void) {
  string s;
  cin >> s;
  int n = s.size();

  if (n >= 3 && !dx[c2i[s[n - 1]]] == !dx[c2i[s[n - 2]]] && !dx[c2i[s[n - 2]]] == !dx[c2i[s[n - 3]]]) {
    cout << "impossible" << endl;
    return 0;
  }

  vector<pair<int, int>> b, p(n + 1);
  for (int i = 0; i < n; i++) {
    int d = c2i[s[i]];

    if (i >= 2) {
      if (c2i[s[i]] == c2i[s[i - 2]] && c2i[s[i]] == (c2i[s[i - 1]] + 2) % 4) {
        p[i + 1] = p[i - 1];
        continue;
      }
    }

    p[i + 1] = {p[i].first + (1 << i) * dx[d], p[i].second + (1 << i) * dy[d]};
    b.push_back({p[i + 1].first + dx[d], p[i + 1].second + dy[d]});
  }
  b.pop_back();

  cout << -p.back().first << " " << -p.back().second << endl;
  cout << b.size() << endl;
  for (auto e : b) {
    cout << e.first - p.back().first << " " << e.second - p.back().second << endl;
  }
}
