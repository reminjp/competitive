#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, t;
	cin >> s;
	for (auto c : s) {
		if (c != 'a' && c != 'i' && c != 'u' && c != 'e' && c != 'o') {
			t.push_back(c);
		}
	}
	cout << t << endl;
	return 0;
}
