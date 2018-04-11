#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> t(n + 1), x(n + 1), y(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> t[i + 1] >> x[i + 1] >> y[i + 1];
  }
  bool r = true;
  for (int i = 0; i < n; i++) {
    int d = (t[i + 1] - t[i]) - abs(x[i + 1] - x[i]) - abs(y[i + 1] - y[i]);
    r &= 0 <= d && d % 2 == 0;
  }
  cout << (r ? "Yes" : "No") << endl;
  return 0;
}
