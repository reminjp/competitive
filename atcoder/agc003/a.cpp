#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	set<char> t;
	for (auto c : s) {
		t.insert(c);
	}
	cout << (t.count('N') == t.count('S') && t.count('W') == t.count('E') ? "Yes" : "No") << endl;
	return 0;
}
