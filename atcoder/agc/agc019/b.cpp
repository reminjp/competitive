#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	vector<ll> m(26);
	for (auto c : s) {
		m[c - 'a']++;
	}
	ll n = (s.size() - 1) * s.size() / 2 + 1;
	for (auto e : m) {
		n -= (e - 1) * e / 2;
	}
	cout << n << endl;
	return 0;
}
