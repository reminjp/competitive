#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, m, a;
  cin >> n >> k >> m >> a;
  if (!(n == 1 && m == 1)) {
    return 1;
  }
  cout << (k < a && (a - k) % 2 ? "Akari" : "Chinatsu") << endl;
}
