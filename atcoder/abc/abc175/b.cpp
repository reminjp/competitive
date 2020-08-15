#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) cin >> e;
  sort(a.begin(), a.end());

  int r = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] == a[j]) continue;
      for (int k = j + 1; k < n; k++) {
        if (a[i] == a[k]) continue;
        if (a[j] == a[k]) continue;
        if (a[i] + a[j] > a[k]) r++;
      }
    }
  }
  cout << r << endl;
}
