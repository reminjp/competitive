#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pow3(ll x) { return x * x * x; }

int main() {
  ll n, k;
  cin >> n >> k;
  cout << pow3(n / k) + (k % 2 ? 0 : pow3((n + k / 2) / k)) << endl;
}
