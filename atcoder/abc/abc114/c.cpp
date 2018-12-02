#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
set<ll> r;

void dfs(string s, bool b3, bool b5, bool b7) {
  if (s.size()) {
    ll a = stoll(s);
    if (a > n) return;
    if (b3 && b5 && b7) r.insert(a);
  }
  dfs(s + "3", true, b5, b7);
  dfs(s + "5", b3, true, b7);
  dfs(s + "7", b3, b5, true);
}

int main() {
  cin >> n;
  dfs("", false, false, false);
  cout << r.size() << endl;
}
