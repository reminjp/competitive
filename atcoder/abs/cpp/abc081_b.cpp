#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int m = 1e9;
  for (int i = 0; i < n; i++) {
    int a, k = 0;
    cin >> a;
    while (a % 2 == 0) {
      a /= 2;
      k++;
    }
    m = min(m, k);
  }
  cout << m << endl;
  return 0;
}
