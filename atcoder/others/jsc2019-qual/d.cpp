#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n, 0));

  function<void(const vector<int>&, int)> f = [&f, &a](const vector<int>& s, int l) {
    for (int i = 0; i < s.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (i % 2 != j % 2) a[s[i]][s[j]] = a[s[j]][s[i]] = l;
      }
    }
    for (int o = 0; o < 2; o++) {
      vector<int> t;
      for (int i = o; i < s.size(); i += 2) t.push_back(s[i]);
      if (t.size() >= 2) f(t, l + 1);
    }
  };
  vector<int> t(n);
  iota(begin(t), end(t), 0);
  f(t, 1);

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) cout << a[i][j] << ' ';
    cout << endl;
  }
}
