#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  string r;
  while (n != 0) {
    n--;
    r.push_back('a' + (n % 26));
    n /= 26;
  }
  reverse(r.begin(), r.end());
  cout << r << endl;
}
