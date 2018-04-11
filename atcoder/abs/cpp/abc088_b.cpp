#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) {
    cin >> e;
  }
  sort(rbegin(a), rend(a));
  vector<int> s(2);
  for (int i = 0; i < n; i++) {
    s[i % 2] += a[i];
  }
  cout << s[0] - s[1] << endl;
  return 0;
}
