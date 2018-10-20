#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] -= i + 1;
  }
  sort(begin(a), end(a));
  int b = a[n / 2];
  long long s = 0;
  for (auto e : a) {
    s += abs(e - b);
  }
  cout << s << endl;
}
