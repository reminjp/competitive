#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string s;
  ll k;
  cin >> s >> k;
  char c = '1';
  for (ll i = 0; i < k; i++) {
    if (s[i] != '1') {
      c = s[i];
      break;
    }
  }
  cout << c << endl;
}
