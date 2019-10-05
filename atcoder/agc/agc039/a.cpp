#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  ll k;
  cin >> s >> k;

  ll r = 0;
  if (k < 5) {
    string t;
    for (int i = 0; i < k; i++) t += s;
    for (int i = 0; i + 1 < t.size(); i++) {
      if (t[i] == t[i + 1]) {
        t[i + 1] = '*';
        r++;
      }
    }
  } else {
    int l = k % 2 ? 5 : 4;
    string t;
    for (int i = 0; i < l; i++) t += s;
    vector<ll> rv(l);
    for (int i = 0; i + 1 < t.size(); i++) {
      if (t[i] == t[i + 1]) {
        t[i + 1] = '*';
        rv[(i + 1) / s.size()]++;
      }
    }
    r += rv.front() + rv.back();
    r += (k - 1) / 2 * rv[1];
    r += (k - 2) / 2 * rv[2];
  }
  cout << r << endl;
}
