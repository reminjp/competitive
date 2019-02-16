#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  int n, r;
  cin >> n >> r;
  for (int i = 1; i < n; i++) {
    int a;
    cin >> a;
    r = gcd(r, a);
  }
  cout << r << endl;
}
