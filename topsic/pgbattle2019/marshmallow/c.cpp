#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<bool> p(m);
  for (int j = 0; j < n; j++) {
    int a, b;
    cin >> a >> b;
    int i = j - (a + b);
    if (0 <= i && i < m) p[i] = true;
  }
  cout << count_if(p.begin(), p.end(), [](int e) { return e; }) << endl;
}
