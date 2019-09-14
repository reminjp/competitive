#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<int> r;
  int k = 1;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == '|') {
      r.push_back(k);
      k = 1;
    } else {
      k++;
      i++;
    }
  }
  r.push_back(k);
  for (auto e : r) cout << e << ' ';
  cout << endl;
}
