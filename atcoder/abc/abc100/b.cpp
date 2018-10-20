#include <bits/stdc++.h>
using namespace std;

int main() {
  int d, n;
  cin >> d >> n;
  if (n >= 100) n++;
  for (; d > 0; d--) n *= 100;
  cout << n << endl;
}
