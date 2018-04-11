#include <iostream>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int s = 0;
  for (int i = 1; i <= n; i++) {
    int t = 0, k = i;
    for (; k != 0; k /= 10) {
      t += k % 10;
    }
    if (a <= t && t <= b) {
      s += i;
    }
  }
  cout << s << endl;
  return 0;
}
