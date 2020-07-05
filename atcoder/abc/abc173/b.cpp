#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<string, int> m;
  while (n--) {
    string s;
    cin >> s;
    m[s]++;
  }

  for (auto e : {"AC", "WA", "TLE", "RE"}) cout << e << " x " << m[e] << endl;
}
