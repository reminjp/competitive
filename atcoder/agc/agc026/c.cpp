#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(const string& s, map<pair<string, string>, ll>& r, string a, string b) {
  int i = a.size() + b.size();
  if (i == s.size() / 2) {
    r[{a, b}]++;
    return;
  }
  dfs(s, r, a + s[i], b);
  dfs(s, r, a, b + s[i]);
}

int main() {
  int n;
  string s;
  cin >> n >> s;

  map<pair<string, string>, ll> u, v;
  dfs(s, u, "", "");
  reverse(begin(s), end(s));
  dfs(s, v, "", "");

  ll m = 0;
  for (auto e : u) {
    m += e.second * v[e.first];
  }
  cout << m << endl;
}
