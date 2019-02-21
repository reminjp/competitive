#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i + 1];
  }
  sort(begin(a) + 1, end(a));
  for (int i = 0; i < n; i++) {
    a[i + 1] += a[i];
  }
  ll r = 0;
  for (int i = 0; i < n; i++) {
    r += i * (a[i + 1] - a[i]) - (a[i] - a[0]);
  }
  cout << r << endl;
}
