#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  set<string> r;
  string s;
  auto dfs = [&](auto&& dfs) {
    if (s.size() == n) {
      r.insert(s);
      return;
    }
    if (s.empty()) {
      s.push_back('a');
      dfs(dfs);
      s.pop_back();
    } else {
      char m = *max_element(s.begin(), s.end()) + 1;
      for (char e = 'a'; e <= m; e++) {
        s.push_back(e);
        dfs(dfs);
        s.pop_back();
      }
    }
  };
  dfs(dfs);

  for (const auto& e : r) cout << e << '\n';
  cout << flush;
}
