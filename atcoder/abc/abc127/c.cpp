#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> s(n + 1);
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    s[l - 1] += 1;
    s[r] += -1;
  }
  for (int i = 0; i < n; i++) s[i + 1] += s[i];
  cout << count_if(s.begin(), s.end(), [m](int e) { return e == m; }) << endl;
}
