#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<int> v(s.size() + 1);
  for (int i = 0; i < s.size(); i++) v[i + 1] = s[i] == 'R' ? v[i] + 1 : 0;
  cout << *max_element(v.begin(), v.end()) << endl;
}
