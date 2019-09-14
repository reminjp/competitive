#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  ll r = 1;
  for (int i = 0; i + 1 < s.size(); i++) r *= (s[i] - 'A' + 1) + (s[i + 1] - 'A' + 1);
  cout << r << endl;
}
