#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  ll r = 0;
  int k = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == 'B') {
      r += s.size() - 1 - k - i;
      k++;
    }
  }
  cout << r << endl;
}
