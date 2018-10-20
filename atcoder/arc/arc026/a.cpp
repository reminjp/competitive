#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  cout << (n <= 5 ? n * b : (n - 5) * a + 5 * b) << endl;
}
