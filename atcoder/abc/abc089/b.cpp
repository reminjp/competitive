#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	bool r = false;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		r |= s.front() == 'Y';
	}
	cout << (r ? "Four" : "Three") << endl;
	return 0;
}
