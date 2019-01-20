#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> h(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> h[i + 1];
  }
  int r = 0;
  for (int i = 0; i < n; i++) {
    r += max(0, h[i + 1] - h[i]);
  }
  cout << r << endl;
}
