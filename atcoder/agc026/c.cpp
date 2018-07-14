#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int n, string s, vector<map<string, ll>>& r, string a, string b) {
  int i = a.size() + b.size();
  if (i == n) {
    reverse(begin(b), end(b));
    r[a.size()][a + b]++;
    return;
  }
  a.push_back(s[i]);
  dfs(n, s, r, a, b);
  a.pop_back();
  b.push_back(s[i]);
  dfs(n, s, r, a, b);
}

int main() {
  int n;
  string s;
  cin >> n >> s;

  vector<map<string, ll>> u(n + 1), v(n + 1);
  dfs(n, s, u, "", "");
  reverse(begin(s), end(s));
  dfs(n, s, v, "", "");

  ll m = 0;
  for (int i = 0; i < n + 1; i++) {
    for (auto e : u[i]) {
      m += e.second * v[i][e.first];
    }
  }
  cout << m << endl;
}
