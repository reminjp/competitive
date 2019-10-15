#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  int a = 1;
  for (int i = 1; i <= 20; i++) a *= i / gcd(i, a);
  cout << a << endl;
}
